#include "Weapon.h"
#include "Components/SphereComponent.h"
#include "Takeover/Components/WeaponComponent.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon Mesh");
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
	WeaponMesh->SetCollisionResponseToAllChannels(ECR_Block);
	WeaponMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	WeaponMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	SetRootComponent(WeaponMesh);

	PickupSphere = CreateDefaultSubobject<USphereComponent>("Pickup Sphere");
	PickupSphere->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	PickupSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	PickupSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	PickupSphere->SetGenerateOverlapEvents(true);
	PickupSphere->SetSphereRadius(75.0f);
	PickupSphere->SetLineThickness(1.0f);
	PickupSphere->ShapeColor = FColor::Green;
	PickupSphere->SetupAttachment(RootComponent);

	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>("Weapon Component");
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	SetWeaponPhysics(true);
}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeapon::SetWeaponPhysics(const bool NewPhysics) const
{
	WeaponMesh->SetSimulatePhysics(NewPhysics);
}

void AWeapon::SetWeaponEvents(const bool NewEvent) const
{
	PickupSphere->SetGenerateOverlapEvents(NewEvent);
}
