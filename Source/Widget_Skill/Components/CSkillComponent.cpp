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
	// #1. �� ���ڿ��̸� return;
	if (RowName.IsEmpty()) return;

	// #2. FName���� ��ȯ / Ű������ Value�� �����͸� ����
	FName SkillRowName(*RowName);
	int32* ExistingCount = SkillUnlockMap.Find(SkillRowName);

	// #3. �ִٸ� 1����  , ���ٸ� ���λ����ؼ� 1 ����
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
	// #1. �� ���ڿ��̸� return;
	if (RowName.IsEmpty()) return false;

	// #2. FName���� ��ȯ / Ű������ Value�� �����͸� ����
	FName SkillRowName(*RowName);
	int32* ExistingCount = SkillUnlockMap.Find(SkillRowName);

	// #3. �ִٸ� DataTable�� ��ϵ� Tier�������� , true ��ȯ / ���ٸ� false
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

