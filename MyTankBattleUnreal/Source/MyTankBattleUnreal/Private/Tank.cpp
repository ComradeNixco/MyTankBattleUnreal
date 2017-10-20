// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

#include "Components/TankAimingComponent.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;

	AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("TankAimingComp"));
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::AimAt(const FVector& Location)
{
	//TODO: Do actual aim
	if (AimingComponent)
	{
		AimingComponent->AimTowards(Location, LaunchSpeed);
	}
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

