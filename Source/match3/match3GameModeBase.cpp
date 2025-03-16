// Copyright Epic Games, Inc. All Rights Reserved.


#include "match3GameModeBase.h"
#include "Match3PlayerController.h"
Amatch3GameModeBase::Amatch3GameModeBase(const FObjectInitializer& ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = APawn::StaticClass();
	PlayerControllerClass = AMatch3PlayerController::StaticClass();
}