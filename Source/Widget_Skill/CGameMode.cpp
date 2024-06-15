#include "CGameMode.h"
////////////////////
#include "Characters/CPlayer.h"
#include "Characters/CPlayerController.h"
#include "CGameInstance.h"
ACGameMode::ACGameMode()
{
	ConstructorHelpers::FClassFinder<ACPlayer> Player(TEXT("Blueprint'/Game/Blueprints/Characters/BP_CPlayer.BP_CPlayer_C'"));
	if (Player.Succeeded())
	{
		DefaultPawnClass = Player.Class;
	}

	ConstructorHelpers::FClassFinder<ACPlayerController> PlayerController(TEXT("Class'/Script/UnrealUMG.CPlayerController'"));
	if (PlayerController.Succeeded())
	{
		PlayerControllerClass = PlayerController.Class;
	}
}