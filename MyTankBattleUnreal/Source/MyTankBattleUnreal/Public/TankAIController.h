// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "TankAIController.generated.h"


class ATank;

/**
 * Specialized AI Controller for Tanks (ATank pawns)
 */
UCLASS()
class MYTANKBATTLEUNREAL_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	/**
	* Obtains the tank controlled by this TankAIController
	* @returns The tank pawn controlled by this TankPlayerController
	*/
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
