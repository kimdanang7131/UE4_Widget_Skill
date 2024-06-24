#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_Skill/Structs/CFSkill.h"
#include "CUserWidget_SkillButton.generated.h"

UCLASS()
class WIDGET_SKILL_API UCUserWidget_SkillButton : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Button")
		void OnButtonClicked();

	UFUNCTION(BlueprintCallable, Category = "Button")
		void UpdateTint();

	UFUNCTION(BlueprintCallable)
		bool CheckPreRequisite();

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (BindWidget))
		class UButton* SkillButton;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (BindWidget))
		class UImage* SkillThumbnail;

	/** DataTable RowName을 이용하여 PreConstruct를 통하여 SkillWindow에 이미지 띄워두기 위해 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Datas")
		FString SkillRowName;
	
	/** 특정 스킬을 오픈키기 위한 전제조건 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Datas")
		FString PreRequisite;

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Owner")
		class ACPlayer* Owner;

	UPROPERTY(BlueprintReadWrite, Category = "Owner")
		class UCUserWidget_SkillWindow* SkillWindow;

	UPROPERTY(BlueprintReadWrite, Category = "Datas")
		FSkill FSkillData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<class UCUserWidget_ToolTip> ToolTipWidgetClass;


private:
	UCUserWidget_ToolTip* ToolTipWidget;

private:
	bool bIsPurchased = false;
};
