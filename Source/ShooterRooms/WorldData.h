// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponDataAsset.h"
#include "WorldData.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERROOMS_API UWorldData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, UWeaponDataAsset*> weaponsList;

};
