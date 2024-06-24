#include "CUserWidget_SkillWindow.h"
////////////////////////////
#include "Widget_Skill/Structs/CFSkill.h"
#include "Widget_Skill/Character/CPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"

void UCUserWidget_SkillWindow::UpdatePerkPoints()
{
	int32 NumPerkPoints = Owner->PerkPoints;
	FString FormattedString = FString::Printf(TEXT("%d Perk Points"), NumPerkPoints);

	// ������ ���ڿ��� �ؽ�Ʈ�� ����
	if (PerkPointText)
	{
		PerkPointText->SetText(FText::FromString(FormattedString));
	}
}

void UCUserWidget_SkillWindow::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UCUserWidget_SkillWindow::NativeConstruct()
{
	Owner = Cast<ACPlayer>(UGameplayStatics::GetPlayerCharacter(this, 0));

	//Owner->Perkpoin
	// C++ ����
	Super::NativeConstruct(); // -> �������Ʈ�� Construct
	UpdatePerkPoints();
}
