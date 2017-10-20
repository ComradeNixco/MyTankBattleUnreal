// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

#include "Engine/World.h"

#include "Tank.h"
#include "TankPlayerController.h"


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATankPlayerController* PlayerController = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());

	// if we have a valid controller, obtains it's linked tank
	return (PlayerController)
		? PlayerController->GetControlledTank()
		: nullptr;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/// Check for Controlled Tank validity
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("%s isn't controlling a pawn"), *this->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	ATank* ControlledTank = GetControlledTank();
	ATank* PlayerTank = GetPlayerTank();
	if (ControlledTank && PlayerTank)
	{
		//TODO: Move towards player

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//TODO: Fire at player
	}
}
