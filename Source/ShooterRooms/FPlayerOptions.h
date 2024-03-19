// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPlayerOptions.generated.h"

USTRUCT(BlueprintType)
struct FPlayerOptions
{

	GENERATED_BODY()
public:

	UPROPERTY(EditAnyWhere, BluePrintReadWrite)
	FString playerName = FString("Player");


public:

	FPlayerOptions() = default;
};