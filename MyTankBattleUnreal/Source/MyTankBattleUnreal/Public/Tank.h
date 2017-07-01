// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class MYTANKBATTLEUNREAL_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY()
		class UTankAimingComponent* AimingComponent;

public:
	// Sets default values for this pawn's properties
	ATank();

	/**
	 * Rotates the turret and barrel to point to the specified location
	 * @param Location Where to point at
	 */
	void AimAt(const FVector& Location);

	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
