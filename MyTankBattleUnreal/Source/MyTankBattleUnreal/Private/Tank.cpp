// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

#include "Runtime/Engine/Classes/Components/InputComponent.h"

#include "Components/TankAimingComponent.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;

	AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

/*void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}*/

void ATank::AimAt(const FVector& Location)
{
	//TODO: Do actual aim
	if (AimingComponent)
	{
		AimingComponent->AimTowards(Location);
	}
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

