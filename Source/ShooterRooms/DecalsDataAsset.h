// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DecalsDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERROOMS_API UDecalsDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UMaterialInstance*> decalsList;
};
