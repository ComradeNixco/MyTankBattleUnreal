// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//TODO: Actual aiming towards the user's crosshair
}

void ATankPlayerController::Tick(float DeltaSecond)
{
	Super::Tick(DeltaSecond);

	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	/*if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possesing a tank"));
	}*/
}
