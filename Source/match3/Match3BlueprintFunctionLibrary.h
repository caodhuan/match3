// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Match3BlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3_API UMatch3BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

public:
	
	// Get a list of all player controllers, then pick the first local one which we find
	UFUNCTION(BlueprintCallable, Category = "Match3 Gameplay", Meta = (WorldContext = "WorldContextObject"))
	static APlayerController* GetLocalPlayerController(UObject* WorldContextObject);

	// Gt the online account ID associated with the provided player controller's player state.
	// Returns a blank string on failure.
	UFUNCTION(BlueprintCallable, Category = "Match3 Gameplay")
	static FString GetOnlineAccountID(APlayerController* PlayerController);


};
