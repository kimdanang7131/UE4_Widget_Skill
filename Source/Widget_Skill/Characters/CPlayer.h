#pragma once

#include "CoreMinimal.h"
#include "CCharacter.h"
#include "CPlayer.generated.h"

UCLASS()
class WIDGET_SKILL_API ACPlayer : public ACCharacter
{
	GENERATED_BODY()
public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	FORCEINLINE int32 GetPerkPoints() { return PerkPoints; }
	FORCEINLINE void SetPerkPoints(const int32& InPerkPoints) { PerkPoints = InPerkPoints; }

public:
	/** SpringArm */
	UPROPERTY(EditDefaultsOnly)
		class USpringArmComponent* SpringArm;

	/** Camera */
	UPROPERTY(EditDefaultsOnly)
		class UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, Category = "SkillWindowInteract")
		int32 PerkPoints = 15;

	/*** Player �Է� ���� ***/
public:
	/** �յ��¿� ������ */
	void OnMoveFB(float InAxis);
	void OnMoveLR(float InAxis);

	/** �����¿� ���콺 ������*/
	void OnHorizontalLook(float InAxis);
	void OnVerticalLook(float InAxis);

	void ToggleSkillWindow();

private:
	bool bSkillWindowVisible = false;
};
