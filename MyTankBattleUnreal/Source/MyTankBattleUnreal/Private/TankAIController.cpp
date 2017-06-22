// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

//#include "Engine/World.h"

#include "Tank.h"
#include "TankPlayerController.h"


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATankPlayerController* PlayerController = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
	if (!PlayerController) { return nullptr; }

	return Cast<ATank>(PlayerController->GetControlledTank());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/// Check for Controlled Tank validity
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("%s isn't controlling a pawn"), *this->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Display,
			TEXT("%s is controlling this pawn tank: %s"),
			*this->GetName(), *ControlledTank->GetName()
		);
	}

	/// Check for player's tank [TEST]
	//ATank* PlayerTank = GetPlayerTank();
	//if (!PlayerTank)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("%s hasn't found first player\'s tank!"), *this->GetName());
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Display,
	//		TEXT("%s has found this as the first player's tank: %s"),
	//		*this->GetName(), *PlayerTank->GetName()
	//	);
	//}
	/// [ENDTEST]
}
