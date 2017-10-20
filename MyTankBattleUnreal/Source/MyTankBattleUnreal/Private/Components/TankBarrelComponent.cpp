// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrelComponent.h"

#include "Runtime/Engine/Classes/Engine/World.h"


void UTankBarrelComponent::Elevate(float RelativeSpeed)
{
	/*UE_LOG(LogTemp, Display,
		TEXT("UTankBarrelComponent::Elevate(%f)"),
		RelativeSpeed
	);*/

	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);

	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewElevation = RelativeRotation.Pitch + ElevationChange;
	
	SetRelativeRotation(FRotator(FMath::Clamp(NewElevation, MinElevation, MaxElevation), 0, 0));
}