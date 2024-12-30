#pragma once

#include "CoreMinimal.h"
#include "WeaponDataSet.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	AssaultRifle,
	SMG,
	Pistol,
	Sniper,
	Melee
};

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EWeaponType WeaponType;
	
	UPROPERTY(EditAnywhere)
	FName WeaponID;
	
	UPROPERTY(EditAnywhere)
	FName Socket;
	
	UPROPERTY(EditAnywhere)
	FText Name;
	
	UPROPERTY(EditAnywhere)
	int32 MaxAmmo;
	
	UPROPERTY(EditAnywhere)
	int32 MaxClipSize;

	FWeaponData() :
	WeaponType(EWeaponType::Melee),
	WeaponID(""),
	Socket(""),
	Name(FText::GetEmpty()),
	MaxAmmo(0),
	MaxClipSize(0)
	{}
};