// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/// UE4's includes
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

/// MyTankBattleUnreal's includes
#include "Tank.h"
#include "TankPlayerController.generated.h"


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
	virtual void BeginPlay() override;

private:
	void AimTowardsCrosshair();
};
