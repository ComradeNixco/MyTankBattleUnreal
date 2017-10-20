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
	UPROPERTY(BlueprintReadOnly)
	class UTankAimingComponent* AimingComponent;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f; // 3.600 km/h (1 km/s or 100'000 cm/s)

public:
	// Sets default values for this pawn's properties
	ATank();

	/**
	 * Rotates the turret and barrel to point to the specified location
	 * @param Location Where to point at
	 */
	void AimAt(const FVector& Location);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void Fire() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
