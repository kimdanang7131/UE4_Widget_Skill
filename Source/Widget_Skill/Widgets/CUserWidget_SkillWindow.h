#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUserWidget_SkillWindow.generated.h"

UCLASS()
class WIDGET_SKILL_API UCUserWidget_SkillWindow : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable, Category = "TextInteract")
		void UpdatePerkPoints();

public:
	UPROPERTY(BlueprintReadWrite, Category = "TextInteract", meta = (BindWidget))
		class UTextBlock* PerkPointText;

	UPROPERTY(BlueprintReadWrite, Category = "Owner")
		class ACPlayer* Owner;
};
