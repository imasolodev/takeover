#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AWeapon;
class ATakeoverCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TAKEOVER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();
	friend class ATakeoverCharacter;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	ATakeoverCharacter* PlayerCharacter = nullptr;

	UPROPERTY(VisibleAnywhere)
	TMap<FName, TSoftClassPtr<AWeapon>> WeaponInventory;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
