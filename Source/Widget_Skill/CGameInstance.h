#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CGameInstance.generated.h"

UCLASS()
class WIDGET_SKILL_API UCGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UCGameInstance();

	virtual void Init() override;
	virtual void Shutdown() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
		TSubclassOf<UUserWidget> MainWindowClass;

public:
	/** PlayerController에서 사용 */
	void MainWindowAddToViewport();
	static class UCUserWidget_MainWindow* GetMainWindowWidget() { return MainWindow; }


private:
	static class UCUserWidget_MainWindow* MainWindow;
};
