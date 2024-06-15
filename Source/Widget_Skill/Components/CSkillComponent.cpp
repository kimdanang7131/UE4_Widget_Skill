#include "CSkillComponent.h"

UCSkillComponent::UCSkillComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UCSkillComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UCSkillComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCSkillComponent::AddSkill(const FString& RowName)
{
	// #1. 빈 문자열이면 return;
	if (RowName.IsEmpty()) return;

	// #2. FName으로 변환 / 키값으로 Value의 포인터를 얻음
	FName SkillRowName(*RowName);
	int32* ExistingCount = SkillUnlockMap.Find(SkillRowName);

	// #3. 있다면 1증가  , 없다면 새로생성해서 1 증가
	if (ExistingCount)
	{
		(*ExistingCount)++;
	}
	else
	{
		SkillUnlockMap.Add(SkillRowName, 1);
	}
}

bool UCSkillComponent::QuerySkill(const FString& RowName, int32& OutTier)
{
	// #1. 빈 문자열이면 return;
	if (RowName.IsEmpty()) return false;

	// #2. FName으로 변환 / 키값으로 Value의 포인터를 얻음
	FName SkillRowName(*RowName);
	int32* ExistingCount = SkillUnlockMap.Find(SkillRowName);

	// #3. 있다면 DataTable에 등록된 Tier내보내기 , true 반환 / 없다면 false
	if (ExistingCount)
	{
		OutTier = (*ExistingCount);
		return true;
	}
	else
	{
		return false;
	}
}

