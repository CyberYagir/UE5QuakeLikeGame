// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Misc/Paths.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"	
#include "GameFramework/GameUserSettings.h"

FString UMyBlueprintFunctionLibrary::ReadFile(FString path, bool& outSuccess)
{
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	FString FileContent = FString("{}");

	if (FileManager.FileExists(*path))
	{
		FFileHelper::LoadFileToString(FileContent, *path, FFileHelper::EHashOptions::None);

		outSuccess = true;
	}
	else {
		outSuccess = false;
	}

	return FileContent;
}

void UMyBlueprintFunctionLibrary::WriteFile(FString path, FString data, bool& outSuccess)
{
	outSuccess = FFileHelper::SaveStringToFile(data, *path);
}

TSharedPtr<FJsonObject> UMyBlueprintFunctionLibrary::ReadJson(FString path, bool& outSuccess)
{
	FString data = ReadFile(path, outSuccess);

	if (!outSuccess) {
		return nullptr;
	}

	TSharedPtr<FJsonObject> retJson;

	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(data), retJson)) {
		outSuccess = false;
		return nullptr;
	}

	outSuccess = true;

	return retJson;
}

void UMyBlueprintFunctionLibrary::WriteJson(FString path, TSharedPtr<FJsonObject> jsonObject, bool& outSuccess)
{
	FString json;

	if (!FJsonSerializer::Serialize(jsonObject.ToSharedRef(), TJsonWriterFactory<>::Create(&json, 0))) {
		outSuccess = false;
		return;
	}

	WriteFile(path, json, outSuccess);
	if (!outSuccess) {
		return;
	}


	outSuccess = true;
}

FServerOptions UMyBlueprintFunctionLibrary::GetServerConfig(FString path, bool& outSuccess)
{
	TSharedPtr<FJsonObject> jsonObject = ReadJson(path, outSuccess);
	if (!outSuccess) {
		return FServerOptions();
	}

	FServerOptions ret;


	if (!FJsonObjectConverter::JsonObjectToUStruct<FServerOptions>(jsonObject.ToSharedRef(), &ret)) {
		outSuccess = false;
		return FServerOptions();
	}

	outSuccess = true;

	return ret;
}

void UMyBlueprintFunctionLibrary::SetServerConfig(FString path, FServerOptions options, bool& outSuccess)
{

	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(options);

	if (JsonObject == nullptr) {
		outSuccess = false;

		return;
	}

	WriteJson(path, JsonObject, outSuccess);

}

FPlayerOptions UMyBlueprintFunctionLibrary::GetPlayerConfig(FString path, bool& outSuccess)
{
	TSharedPtr<FJsonObject> jsonObject = ReadJson(path, outSuccess);
	if (!outSuccess) {
		return FPlayerOptions();
	}

	FPlayerOptions ret;


	if (!FJsonObjectConverter::JsonObjectToUStruct<FPlayerOptions>(jsonObject.ToSharedRef(), &ret)) {
		outSuccess = false;
		return FPlayerOptions();
	}

	outSuccess = true;

	return ret;
}

void UMyBlueprintFunctionLibrary::SetPlayerConfig(FString path, FPlayerOptions options, bool& outSuccess)
{

	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(options);

	if (JsonObject == nullptr) {
		outSuccess = false;

		return;
	}

	WriteJson(path, JsonObject, outSuccess);
}



void UMyBlueprintFunctionLibrary::DisableRendering(AActor* actor)
{
	UGameViewportClient* ViewportClient = actor->GetWorld()->GetGameViewport();
	ViewportClient->bDisableWorldRendering = true;
}

void UMyBlueprintFunctionLibrary::EnableRendering(AActor* actor)
{
	UGameViewportClient* ViewportClient = actor->GetWorld()->GetGameViewport();
	if (ViewportClient->bDisableWorldRendering) {
		ViewportClient->bDisableWorldRendering = false;
	}
}


