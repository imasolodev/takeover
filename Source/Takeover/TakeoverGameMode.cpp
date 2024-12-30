// Copyright Epic Games, Inc. All Rights Reserved.

#include "TakeoverGameMode.h"
#include "TakeoverCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATakeoverGameMode::ATakeoverGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
