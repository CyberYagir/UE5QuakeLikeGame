// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FServerOptions.generated.h"

UENUM(BlueprintType)
enum class EGameType : uint8 {
	GT_DM       UMETA(DisplayName = "Deathmatch"),
	GT_TDM        UMETA(DisplayName = "Team Deathmatch"),
	GT_Flag        UMETA(DisplayName = "Capture Flag"),
};

USTRUCT(BlueprintType)
struct FServerOptions
{

	GENERATED_BODY()
public:

	UPROPERTY(EditAnyWhere, BluePrintReadWrite)
	FString serverName = FString("Server");
	UPROPERTY(EditAnyWhere, BluePrintReadWrite)
	int roundTime = 600;
	UPROPERTY(EditAnyWhere, BluePrintReadWrite)
	int maxPlayers = 10;
	UPROPERTY(EditAnyWhere, BluePrintReadWrite)
	FString mapName = FString("Map1");
	UPROPERTY(EditAnyWhere, BluePrintReadWrite)
	EGameType gameType = EGameType::GT_DM;



public:

	FServerOptions() = default;
};
