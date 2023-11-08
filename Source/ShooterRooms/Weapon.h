// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"


UENUM(BlueprintType)
enum class EWeaponState : uint8 {
	VE_Equip       UMETA(DisplayName = "Eqiup"),
	VE_Idle        UMETA(DisplayName = "Idle"),
	VE_Shoot        UMETA(DisplayName = "Shoot"),
	VE_Dequip       UMETA(DisplayName = "Dequip")
};

UCLASS()
class SHOOTERROOMS_API AWeapon : public AActor
{
	GENERATED_BODY()
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float shootDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWeaponState weaponState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool waitForEquip;

	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Shoot();

	UFUNCTION(BlueprintCallable)
	void StopShoot();


	UFUNCTION(BlueprintCallable)
	void DeEquipAnimation();


	UFUNCTION(BlueprintImplementableEvent)
	void OnShoot();
	UFUNCTION(BlueprintImplementableEvent)
	void OnStopShoot();

	UFUNCTION(BlueprintImplementableEvent)
	void DeEquip();
};
