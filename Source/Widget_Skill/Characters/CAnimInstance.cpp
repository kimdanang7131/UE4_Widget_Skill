#include "CAnimInstance.h"
////////////////////////////
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

/** Animinstance의 BeginPlay */
void UCAnimInstance::NativeBeginPlay()
{
	// #1. 본체를 얻어서 character에 등록 
	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());

	if (OwnerCharacter == nullptr)
		return;
}

/** Animinstance의 UpdateAnimation */
void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (OwnerCharacter == nullptr)
	{
		OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	}

	if (OwnerCharacter == nullptr)
		return;

	Speed    = OwnerCharacter->GetVelocity().Size2D();
	bIsInAir = OwnerCharacter->GetCharacterMovement()->IsFalling();
	bIsAccelerating = OwnerCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
	Direction = CalculateDirection(OwnerCharacter->GetVelocity(), FRotator(0, OwnerCharacter->GetControlRotation().Yaw, 0));
}