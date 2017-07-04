// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTankAimingComponent::AimTowards(const FVector& Location)
{
	/*UE_LOG(LogTemp, Display,
		TEXT("%s is aiming towards %s"),
		*GetOwner()->GetName(), *Location.ToString()
	);*/

	if (Barrel)
	{
		UE_LOG(LogTemp, Warning,
			TEXT("%s is aiming towards %s; Barrel at: %s"),
			*GetOwner()->GetName(), *Location.ToString(), *Barrel->GetComponentLocation().ToString()
		);
	}
}

void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

