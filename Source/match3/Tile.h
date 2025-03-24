// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "Tile.generated.h"


// UENUM()
// namespace ETileState
// {
// 	enum Type
// 	{
// 		ETS_NORMAL,
// 		ETS_FALLING,
// 		ETS_PENDINGDELETE,
// 	};
// }


USTRUCT(BlueprintType)
struct FTileAbilities
{
  	GENERATED_USTRUCT_BODY();

	bool CanExplode() { return bExplodes; }

	bool CanSwap() { return (!bPreventSwapping && !bExplodes); }

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
 	int32 BombPower = 0;

	FileAbilities() : bExplodes(0), bPreventSwapping(0)
	{
		
	}

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
 	uint32 bExplodes : 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint32 bPreventSwapping : 1;
};

UCLASS()
class MATCH3_API ATile : public APaperSpriteActor
{
	GENERATED_BODY()

public:
	ATile();

	void BeginPlay() override;
	
		
	UFUNCTION()
	void TilePress(ETouchIndex::Type FingerIndex, AActor* TouchedActor);

	UFUNCTION()
	void TileEnter(ETouchIndex::Type FingerIndex, AActor* TouchedActor);

protected:

	class AGrid* Grid;
};
