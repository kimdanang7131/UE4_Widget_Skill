#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CSkillComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WIDGET_SKILL_API UCSkillComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	friend class ACCharacter;
public:	
	UCSkillComponent();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Widget���� ��ư Ŭ������ ��ų �߰� ���� */
	UFUNCTION(BlueprintCallable, Category = "SkillWidgetInteract")
		void AddSkill(const FString& RowName);

	/** Widget���� ��ư Ŭ���� DataTable�� �ִ��� Ȯ�� */
	UFUNCTION(BlueprintCallable, Category = "SkillWidgetInteract")
		bool QuerySkill(const FString& RowName, int32& OutTier);

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TMap<FName, int32> SkillUnlockMap;

private:
	class ACharacter* OwnerCharacter;
};
