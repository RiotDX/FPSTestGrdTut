// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TestingGroundTutGameMode.h"
#include "TestingGroundTutHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestingGroundTutGameMode::ATestingGroundTutGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Blueprints/FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGroundTutHUD::StaticClass();
}
