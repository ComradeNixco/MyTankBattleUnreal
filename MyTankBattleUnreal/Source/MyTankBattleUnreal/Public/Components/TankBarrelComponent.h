// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrelComponent.generated.h"


/**
 * Component managing the barrel of a tank
 */
UCLASS(ClassGroup=(Tank), HideCategories=("Collision"),	meta=(BlueprintSpawnableComponent))
class MYTANKBATTLEUNREAL_API UTankBarrelComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category=Movement)
	float MaxDegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category=Movement)
	float MinElevation = 0;
	UPROPERTY(EditAnywhere, Category=Movement)
	float MaxElevation = 35;
};
