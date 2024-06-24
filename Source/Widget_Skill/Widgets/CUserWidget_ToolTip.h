#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUserWidget_ToolTip.generated.h"

UCLASS()
class WIDGET_SKILL_API UCUserWidget_ToolTip : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	FORCEINLINE void SetIsPurchased(bool InPurchased) { bIsPurchased = InPurchased; }
	FORCEINLINE void SetFSkillData(FSkill InFSkill) { FSkillData = InFSkill; }
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* SkillNameText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* DescriptionText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* CostText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* RestrictionText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FSkill FSkillData;

	UPROPERTY(BlueprintReadWrite)
		bool bIsPurchased;

public:
	UFUNCTION(BlueprintCallable)
		void UpdateToolTip();

};
