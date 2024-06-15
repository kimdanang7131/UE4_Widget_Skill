#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CFSkill.generated.h"

USTRUCT(BlueprintType)
struct FSkill : public FTableRowBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 Cost = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        class UTexture2D* Thumbnail;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 Tiers;

};
