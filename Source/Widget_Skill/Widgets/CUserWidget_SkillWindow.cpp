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

	// 생성된 문자열을 텍스트로 설정
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
	// C++ 내용
	Super::NativeConstruct(); // -> 블루프린트의 Construct
	UpdatePerkPoints();
}
