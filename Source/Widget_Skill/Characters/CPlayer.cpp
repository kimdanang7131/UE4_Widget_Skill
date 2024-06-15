#include "CPlayer.h"
//////////////////
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	// #1. SpringArm 설정
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetMesh());

	{
		SpringArm->SetRelativeLocation(FVector(0, 0, 160));
		SpringArm->SetRelativeRotation(FRotator(0, 90, 0));
		SpringArm->SocketOffset = FVector(0, 0, 40.f);
		SpringArm->TargetArmLength = 350.f;

		SpringArm->bDoCollisionTest = false;
		SpringArm->bEnableCameraLag = true;
		SpringArm->bUsePawnControlRotation = true;
	}

	// #2. Camrea 설정
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::OnMoveFB);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveLR);

	PlayerInputComponent->BindAxis("HorizontalLook", this, &ACPlayer::OnHorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook", this, &ACPlayer::OnVerticalLook);
}


/** 앞뒤좌우 움직임 */
void ACPlayer::OnMoveFB(float InAxis)
{
	FRotator Rotator = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	FVector Direction = FQuat(Rotator).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(Direction, InAxis);
}

void ACPlayer::OnMoveLR(float InAxis)
{
	FRotator Rotator = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	FVector Direction = FQuat(Rotator).GetRightVector().GetSafeNormal2D();

	AddMovementInput(Direction, InAxis);
}


/** 상하좌우 마우스 움직임*/
void ACPlayer::OnHorizontalLook(float InAxis)
{
	AddControllerYawInput(InAxis);
}

void ACPlayer::OnVerticalLook(float InAxis)
{
	AddControllerPitchInput(InAxis);
}
