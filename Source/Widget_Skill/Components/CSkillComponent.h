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

	/** Widget에서 버튼 클릭으로 스킬 추가 연동 */
	UFUNCTION(BlueprintCallable, Category = "SkillWidgetInteract")
		void AddSkill(const FString& RowName);

	/** Widget에서 버튼 클릭시 DataTable에 있는지 확인 */
	UFUNCTION(BlueprintCallable, Category = "SkillWidgetInteract")
		bool QuerySkill(const FString& RowName, int32& OutTier);

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TMap<FName, int32> SkillUnlockMap;

private:
	class ACharacter* OwnerCharacter;
};
