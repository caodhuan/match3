// Fill out your copyright notice in the Description page of Project Settings.


#include "Match3BlueprintFunctionLibrary.h"
#include "GameFramework/PlayerState.h"

APlayerController* UMatch3BlueprintFunctionLibrary::GetLocalPlayerController(UObject* WorldContextObject)
{
    if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
    {
        for (FConstPlayerControllerIterator Iterator = World->GetPlayerControllerIterator(); Iterator; ++ Iterator)
        {
            APlayerController* playerController = Iterator->Get();
            if (playerController && playerController->IsLocalController())
            {
                return playerController;
            }
        }
    }
    return nullptr;
}

FString UMatch3BlueprintFunctionLibrary::GetOnlineAccountID(APlayerController* PlayerController)
{
    if (PlayerController && PlayerController->PlayerState && PlayerController->PlayerState->GetUniqueId().IsValid())
    {
        return PlayerController->PlayerState->GetUniqueId()->GetHexEncodedString();
    }
    return FString();
}
