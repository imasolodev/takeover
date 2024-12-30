#include "TakeoverController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Takeover/Characters/TakeoverCharacter.h"

ATakeoverController::ATakeoverController()
{
	
}

void ATakeoverController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<ATakeoverCharacter>(GetPawn());
}

void ATakeoverController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::StopJumping);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
	}
}

void ATakeoverController::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (PlayerCharacter)
	{
		PlayerCharacter->AddMovementInput(ForwardDirection, MovementVector.Y);
		PlayerCharacter->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ATakeoverController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (PlayerCharacter)
	{
		PlayerCharacter->AddControllerYawInput(LookAxisVector.X);
		PlayerCharacter->AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ATakeoverController::Jump(const FInputActionValue& Value)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->Jump();
	}
}

void ATakeoverController::StopJumping(const FInputActionValue& Value)
{
	if (PlayerCharacter)
	{
		PlayerCharacter->StopJumping();
	}
}
