// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Weapon.h"
#include "PaperSprite.h"
#include "WeaponDataAsset.generated.h"
/**
 * 
 */
UCLASS()
class SHOOTERROOMS_API UWeaponDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	

	public:

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int maxBullets;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int minBullets;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int secondaryAddAmmoValue;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float removeBullets;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float damage;


		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AWeapon> weaponClass;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMesh* mesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperSprite* icon;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Server)
		int tickRate = 0;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Client)
		TArray<UMaterialInstance*> clientMaterals;



		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Client)
		FTransform clientTransformOffcet;

};
