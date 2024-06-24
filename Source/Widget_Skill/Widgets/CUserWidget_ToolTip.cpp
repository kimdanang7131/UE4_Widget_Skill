#include "CUserWidget_ToolTip.h"
////////////////////////
#include "Components/TextBlock.h"
#include "Engine/DataTable.h"

void UCUserWidget_ToolTip::NativePreConstruct()
{
	if (FSkillData.Name.IsEmpty()) return;

	if (SkillNameText)
	{
		SkillNameText->SetText(FSkillData.Name);
	}

	if (CostText)
	{
		FString FormattedString = FString::Printf(TEXT("Requires %d Perk Points"), FSkillData.Cost);
		CostText->SetText(FText::FromString(FormattedString));
	}

	if (DescriptionText)
	{
		DescriptionText->SetText(FSkillData.Description);
	}

	if (RestrictionText)
	{
		RestrictionText->SetText(FText::GetEmpty());
	}

	bIsPurchased = false;

	Super::NativePreConstruct();
}

void UCUserWidget_ToolTip::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCUserWidget_ToolTip::UpdateToolTip()
{
	if (bIsPurchased)
	{
		CostText->SetText(FText::GetEmpty());
	}
}

