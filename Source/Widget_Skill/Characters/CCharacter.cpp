#include "CCharacter.h"
/////////////////////
#include "Widget_Skill/Components/CSkillComponent.h"
/////////////////////
#include "GameFramework/CharacterMovementComponent.h"

ACCharacter::ACCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SkillComp = CreateDefaultSubobject<UCSkillComponent>(TEXT("SkillComponent"));

	// #1. 캐릭터 기본 설정 -> 키 입력한 방향으로 캐릭터 회전
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void ACCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (SkillComp)
	{
		SkillComp->OwnerCharacter = this;
	}
}



