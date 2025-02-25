// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

#include "Engine/World.h"
#include "Tank.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLoc;
	if (GetSightRayHitLocation(HitLoc))
	{
		/// Landscape was hit
		float DistanceInMeters = FVector::Distance(GetPawn()->GetActorLocation(), HitLoc) / 100.f;
		GetControlledTank()->AimAt(HitLoc);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector::ZeroVector;
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = CrosshairLocation * FVector2D(ViewportSizeX, ViewportSizeY);

	/// WorldDirection is a unit vector pointing in the direction the player is watching
	FVector WorldDirection;
	if (!GetLookDirection(ScreenLocation, WorldDirection))
	{
		return false;
	}

	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + (WorldDirection * SightRange);
	FHitResult Hit;
	bool bSuccess = GetWorld()->LineTraceSingleByChannel(
		Hit,
		Start, End,
		ECollisionChannel::ECC_Visibility, FCollisionQueryParams(FName(""), true, GetPawn())
	);

	OutHitLocation = bSuccess ? Hit.Location : FVector::ZeroVector;
	return bSuccess;
}

bool ATankPlayerController::GetLookDirection(const FVector2D& ScreenLocation, FVector& OutLookDirection) const
{
	FVector v;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, ScreenLocation.Y,
		v, OutLookDirection
	);
}

void ATankPlayerController::Tick(float DeltaSecond)
{
	Super::Tick(DeltaSecond);

	AimTowardsCrosshair();
}

/*void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//ATank* ControlledTank = GetControlledTank();
}*/
