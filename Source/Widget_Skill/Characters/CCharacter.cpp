#include "CCharacter.h"
/////////////////////
#include "Widget_Skill/Components/CSkillComponent.h"
/////////////////////
#include "GameFramework/CharacterMovementComponent.h"

ACCharacter::ACCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SkillComp = CreateDefaultSubobject<UCSkillComponent>(TEXT("SkillComponent"));

	// #1. ĳ���� �⺻ ���� -> Ű �Է��� �������� ĳ���� ȸ��
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



