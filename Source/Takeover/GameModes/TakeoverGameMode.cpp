#include "TakeoverGameMode.h"
#include "UObject/ConstructorHelpers.h"

ATakeoverGameMode::ATakeoverGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<AController> BPController(TEXT("/Game/ThirdPerson/Blueprints/BP_TakeoverController"));
	if (BPController.Class)
	{
		PlayerControllerClass = BPController.Class;
	}
}
