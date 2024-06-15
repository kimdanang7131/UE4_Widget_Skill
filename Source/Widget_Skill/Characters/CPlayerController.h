#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

UCLASS()
class WIDGET_SKILL_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACPlayerController();
	virtual void BeginPlay() override;

public:
	class UCGameInstance* GameInstance;
};
