// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/// UE4's includes
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"

// float representing one third at the best of the compiler possibility
#define ONE_THIRD	(1.f/3.f)

class ATank;

constexpr float kmToCm(float km) 
{
	//      to  meters   cm
	return km * 1000.f * 100.f; 
}

/**
 * PlayerController specialized to Tank pawns
 */
UCLASS()
class MYTANKBATTLEUNREAL_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	/**
	 * Obtains the tank controlled by this TankPlayerController
	 * @returns The tank pawn controlled by this TankPlayerController
	 */
	UFUNCTION(BlueprintCallable)
	ATank* GetControlledTank() const;

public:
	/**
	 * Called each tick
	 * @param DeltaSecond Time delta in seconds since last tick
	 */
	virtual void Tick(float DeltaSecond) override;

protected:
	/**
	 * Called when this begins to play
	 */
	//virtual void BeginPlay() override;

private:
	/**
	 * Does necessary calculations to obtain where (in the world) to aim regarding of the users crosshair
	 */
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	/**
	 * Obtains the direction the players looking related to the ScreenLocation
	 * @param ScreenLocation Position to be deprojected to obtain direction
	 * @param OutLookDirection Unit vector representing the direction of the camera at the given ScreenLocation
	 * @returns true if deprojection was successful; false otherwise
	 */
	bool GetLookDirection(const FVector2D& ScreenLocation, FVector& OutLookDirection) const;

	UPROPERTY(EditAnywhere)
		FVector2D CrosshairLocation = FVector2D(0.5f, ONE_THIRD);
	UPROPERTY(EditAnywhere)
		float SightRange = kmToCm(10.f);
};
