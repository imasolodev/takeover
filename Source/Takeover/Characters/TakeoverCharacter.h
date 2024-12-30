#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TakeoverCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS(config=Game)
class ATakeoverCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATakeoverCharacter();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

public:
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
