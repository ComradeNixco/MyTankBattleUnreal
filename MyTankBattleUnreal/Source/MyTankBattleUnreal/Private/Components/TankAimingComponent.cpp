// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

#include "Runtime/Engine/Classes/GameFramework/Actor.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "TankBarrelComponent.h"
#include "TankTurretComponent.h"

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::AimTowards(const FVector& Location, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector LaunchVelocity;
	const FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (UGameplayStatics::SuggestProjectileVelocity(this,
		LaunchVelocity,
		StartLocation, Location, LaunchSpeed,
		false, 0.f, 0.f,
		ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		const FVector AimDirection = LaunchVelocity.GetSafeNormal();
		MoveTurretTowards(AimDirection);

		/*UE_LOG(LogTemp, Warning,
			TEXT("%s is aiming towards %s; Barrel at: %s; Aiming direction: %s"),
			*GetOwner()->GetName(), *Location.ToString(),
			*Barrel->GetComponentLocation().ToString(), *AimDirection.ToString()
		);*/
	}
}

void UTankAimingComponent::MoveTurretTowards(const FVector& AimDirection)
{
	if (!Turret) { return; }

	// Work-out difference between current barrel rotation and AimDirection
	// Move the barrel the right amount this frame
	// Given a max elevation speed and the frame time

	FRotator BarrelRotator = Barrel->GetForwardVector().ToOrientationRotator();
	FRotator AimRotator = AimDirection.ToOrientationRotator();

	FRotator DeltaBarrelRot = AimRotator - BarrelRotator;
	FRotator TurretRotator = AimRotator - Turret->GetForwardVector().ToOrientationRotator();

	Barrel->Elevate(DeltaBarrelRot.Pitch);
	Turret->Rotate(TurretRotator.Yaw);
}

//void UTankAimingComponent::BeginPlay()
//{
//	Super::BeginPlay();
//}


/*void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}*/

