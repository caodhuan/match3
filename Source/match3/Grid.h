// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

class ATile;

UCLASS()
class MATCH3_API AGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	void OnTileWasSelected(ATile* SelectedTile);


private:
	// Tiles that are currently falling
	TArray<ATile*> FallingTiles;
	
	// Tiles that are currently reacting to being matches
	TArray<ATile*> TilesBeingDestroyed;

	// Indicates that we are waitting to complete a swap move.
	// When SwappingTiles is populated by two tiles, we are done.
	uint32 bPendingSwapMove : 1;
	uint32 bPendingSwapMoveSuccess : 1;
};
