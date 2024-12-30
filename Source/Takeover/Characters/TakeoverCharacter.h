#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TakeoverCharacter.generated.h"

class UInventoryComponent;
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
	virtual void PostInitializeComponents() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInventoryComponent> InventoryComponent;

public:
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	FORCEINLINE UInventoryComponent* GetInventoryComponent() const { return InventoryComponent; }
};
