#include "CUserWidget_SkillButton.h"
//////////////////
#include "Widget_Skill/Characters/CPlayer.h"
#include "Widget_Skill/CGameInstance.h"
#include "Widget_Skill/Components/CSkillComponent.h"

#include "CUserWidget_ToolTip.h"
#include "CUserWidget_MainWindow.h"
#include "CUserWidget_SkillWindow.h"
//////////////////
#include "Engine/DataTable.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

void UCUserWidget_SkillButton::NativePreConstruct()
{
	if (SkillRowName.IsEmpty()) return;

	// #1. FString을 FName으로 변환 
	FName SkillRowName_FName(*SkillRowName);

	// #2. LoadObject ( FObjectFinder와 비슷 )을 통해 DataTable을 가져옴
	UDataTable* SkillTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/Blueprints/DataTable/DT_Skill.DT_Skill'"));
	if (SkillTable)
	{
		// #3. DataTable의 행 이름을 통해 Struct를 가져옴
		FSkill* FoundSkillData = SkillTable->FindRow<FSkill>(SkillRowName_FName, TEXT("SkillData"));

		if (FoundSkillData)
		{
			FSkillData = *FoundSkillData;
			if (SkillThumbnail && FSkillData.Thumbnail)
			{
				//#4. 이미지 설정
				SkillThumbnail->GetDynamicMaterial()->SetTextureParameterValue(FName("SkillIcon"), FSkillData.Thumbnail);
				SkillThumbnail->GetDynamicMaterial()->SetScalarParameterValue(FName("DesaturationValue"), 1.f);

				ToolTipWidget = CreateWidget<UCUserWidget_ToolTip>(this, ToolTipWidgetClass, TEXT("ToolTipWidget"));
				ToolTipWidget->SetFSkillData(FSkillData);
				SetToolTip(ToolTipWidget);


				UDataTable* SkillNameTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/Blueprints/DataTable/DT_Skill.DT_Skill'"));
				FName PreRequisiteName_FName(*PreRequisite);
				if (SkillNameTable)
				{
					FSkill* SkillNameFSkill = SkillNameTable->FindRow<FSkill>(PreRequisiteName_FName, TEXT("SkillName"));
					if (SkillNameFSkill)
					{
						FString FormattedString = FString::Printf(TEXT("Requires %s"), *SkillNameFSkill->Name.ToString());
						ToolTipWidget->RestrictionText->SetText(FText::FromString(FormattedString));
					}
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("ButtonError"));
		}
	}



	Super::NativePreConstruct();
}

void UCUserWidget_SkillButton::NativeConstruct()
{
	Owner = Cast<ACPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0));
	SkillWindow = UCGameInstance::GetMainWindowWidget()->GetSkillWindow();

	if (Owner)
		Owner->SkillComp = Cast<UCSkillComponent>(Owner->GetComponentByClass(UCSkillComponent::StaticClass()));

	SkillButton->OnClicked.AddDynamic(this, &UCUserWidget_SkillButton::OnButtonClicked);
	UCGameInstance::GetMainWindowWidget()->OnSkillWindowDelegate.AddDynamic(this, &UCUserWidget_SkillButton::UpdateTint);

	Super::NativeConstruct(); // -> 블루프린트의 Construct
}

void UCUserWidget_SkillButton::OnButtonClicked()
{
	if (FSkillData.Thumbnail == nullptr) return;

	if (CheckPreRequisite())
	{
		// #1. 버튼을 누른 스킬의 Cost가 PerkPoint보다 작다면 등록가능
		if (Owner->GetPerkPoints() >= FSkillData.Cost && !bIsPurchased)
		{
			Owner->SetPerkPoints(Owner->GetPerkPoints() - FSkillData.Cost);

			if (SkillWindow)
				SkillWindow->UpdatePerkPoints();

			SkillThumbnail->GetDynamicMaterial()->SetScalarParameterValue(FName("DesaturationValue"), 0.f);
			bIsPurchased = true;
			ToolTipWidget->SetIsPurchased(bIsPurchased);
			ToolTipWidget->UpdateToolTip();

			if (Owner->SkillComp)
			{
				Owner->SkillComp->AddSkill(SkillRowName);
				int32 Tier;
				Owner->SkillComp->QuerySkill(SkillRowName, Tier);
			}

			if (UCGameInstance::GetMainWindowWidget()->OnSkillWindowDelegate.IsBound())
				UCGameInstance::GetMainWindowWidget()->OnSkillWindowDelegate.Broadcast();
		}
		else
		{
			return;
		}
	}
}

void UCUserWidget_SkillButton::UpdateTint()
{
	if (CheckPreRequisite() && !bIsPurchased && Owner->GetPerkPoints() >= FSkillData.Cost)
	{
		// #1. 찍을 수 있다면 노란색
		SkillThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1.0f, 1.0f, 0.0f, 1.f)));
	}
	else
	{
		// #2. 이미 찍었거나 Cost가 부족하여 찍지 못할 때 본래 색깔
		SkillThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1.0f, 1.0f, 1.0f, 1.f)));
	}
}

bool UCUserWidget_SkillButton::CheckPreRequisite()
{
	int32 Tier = 0;

	// #1. 전제조건이 없다면 true
	if (PreRequisite.IsEmpty())
		return true;

	bool bHasSkill;
	bHasSkill = Owner->SkillComp->QuerySkill(PreRequisite, Tier);
	if (bHasSkill)
	{
		if (ToolTipWidget)
		{
			PreRequisite = TEXT("");
			ToolTipWidget->RestrictionText->SetText(FText::FromString(PreRequisite));
		}
	}

	return  bHasSkill;
}