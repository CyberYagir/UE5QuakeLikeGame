// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FServerOptions.h"
#include "MyBlueprintFunctionLibrary.generated.h"

class FJsonObject;


UCLASS()
class SHOOTERROOMS_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static FString ReadFile(FString path, bool& outSuccess);
	UFUNCTION(BlueprintCallable)
	static void WriteFile(FString path, FString data, bool& outSuccess);
	static TSharedPtr<FJsonObject> ReadJson(FString path, bool& outSuccess);
	static void WriteJson(FString path, TSharedPtr<FJsonObject> jsonObject, bool& outSuccess);

	UFUNCTION(BlueprintCallable)
	static FServerOptions GetServerConfig(FString path, bool& outSuccess);
	UFUNCTION(BlueprintCallable)
	static void SetServerConfig(FString path, FServerOptions options, bool& outSuccess);
	UFUNCTION(BlueprintCallable)
	static void DisableRendering(AActor* actor);
};
