// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"
#include "Grid.h"
#include "Kismet/GameplayStatics.h"
#include "PaperSpriteComponent.h"

ATile::ATile()
{
	PrimaryActorTick.bCanEverTick = false;

	if (RootComponent)
	{
		RootComponent->SetMobility(EComponentMobility::Movable);
	}
}

void ATile::BeginPlay()
{
	Super::BeginPlay();

	Grid = Cast<AGrid>(GetOwner());

	OnInputTouchBegin.AddUniqueDynamic(this, &ATile::TilePress);

	OnInputTouchEnter.AddUniqueDynamic(this, &ATile::TileEnter);
}

void ATile::TilePress(ETouchIndex::Type FingerIndex, AActor* TouchedActor)
{
	if (UGameplayStatics::IsGamePaused(this))
	{
		return;
	}

	if (!Grid)
	{
		return;
	}

	Grid->OnTileWasSelected(this);
}

void ATile::TileEnter(ETouchIndex::Type FingerIndex, AActor* TouchedActor)
{
	if (UGameplayStatics::IsGamePaused(this))
	{
		return;
	}

	if (!Grid)
	{
		return;
	}

}


