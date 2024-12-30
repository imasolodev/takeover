#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Takeover/Data/WeaponDataSet.h"
#include "WeaponComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TAKEOVER_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UWeaponComponent();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 AmmoCount = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 ClipCount = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FWeaponData WeaponData;

public:
	FORCEINLINE int32 GetAmmoCount() const { return AmmoCount; }
	FORCEINLINE int32 GetClipCount() const { return ClipCount; }
	FORCEINLINE void SetAmmoCount(const int32 NewAmmoCount) { AmmoCount = NewAmmoCount; }
	FORCEINLINE void SetClipCount(const int32 NewClipCount) { ClipCount = NewClipCount; }
	FORCEINLINE FWeaponData GetWeaponData() const { return WeaponData; }
};
