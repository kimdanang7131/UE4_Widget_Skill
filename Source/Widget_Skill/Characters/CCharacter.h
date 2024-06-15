#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CCharacter.generated.h"

UCLASS()
class WIDGET_SKILL_API ACCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACCharacter();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Components")
		class UCSkillComponent* SkillComp;
};
