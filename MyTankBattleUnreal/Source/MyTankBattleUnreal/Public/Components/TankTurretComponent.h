// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurretComponent.generated.h"

/**
 * Component managing a tank's turret behavior
 */
UCLASS(ClassGroup = (Tank), HideCategories = ("Collision"), meta = (BlueprintSpawnableComponent))
class MYTANKBATTLEUNREAL_API UTankTurretComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	/**
	 * Rotates this component at the desired speed in relation with the max speed with the specified relative speed
	 * @param RelativeSpeed Relative speed of rotation in the interval [-1..1]; will be multiplied by MaxDegreesPerSecond (lerped) to obtain real speed in consideration of the current frame's time
	 */
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category=Movement)
	float MaxDegreesPerSecond = 20.f;
};
