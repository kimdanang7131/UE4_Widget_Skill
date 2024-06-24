#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUserWidget_MainWindow.generated.h"

UCLASS()
class WIDGET_SKILL_API UCUserWidget_MainWindow : public UUserWidget
{
	GENERATED_BODY()
	
public:
	FORCEINLINE class UCUserWidget_SkillWindow* GetSkillWindow() { return SkillWindow; }
public:
	/** InputMode , Visibility , ShowMouseCursor ¼³Á¤ */
	UFUNCTION(BlueprintCallable, Category = "SkillWindow")
		void SetSkillWindowVisibility(bool bIsvisible);

	UPROPERTY(EditDefaultsOnly, Category = "SkillWindow", meta = (BindWidget))
		UCUserWidget_SkillWindow* SkillWindow;
};
