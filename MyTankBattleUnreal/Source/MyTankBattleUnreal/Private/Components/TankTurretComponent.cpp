// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurretComponent.h"

#include "Runtime/Engine/Classes/Engine/World.h"


void UTankTurretComponent::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);

	float NewRotation = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	NewRotation += RelativeRotation.Yaw;

	SetRelativeRotation(FRotator(0, NewRotation, 0));
}
