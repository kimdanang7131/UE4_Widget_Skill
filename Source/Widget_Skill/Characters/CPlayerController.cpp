#include "CPlayerController.h"
///////////////////////
#include "Widget_Skill/CGameInstance.h"

ACPlayerController::ACPlayerController()
{

}

void ACPlayerController::BeginPlay()
{
	GameInstance = Cast<UCGameInstance>(GetGameInstance());
	if (GameInstance)
	{
		GameInstance->MainWindowAddToViewport();
	}
}