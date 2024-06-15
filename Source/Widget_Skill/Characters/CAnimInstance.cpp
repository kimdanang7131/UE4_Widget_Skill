#include "CAnimInstance.h"
////////////////////////////
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

/** Animinstance�� BeginPlay */
void UCAnimInstance::NativeBeginPlay()
{
	// #1. ��ü�� �� character�� ��� 
	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());

	if (OwnerCharacter == nullptr)
		return;
}

/** Animinstance�� UpdateAnimation */
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