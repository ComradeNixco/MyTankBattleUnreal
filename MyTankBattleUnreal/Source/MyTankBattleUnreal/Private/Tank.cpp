// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Components/InputComponent.h"

// Sets default values
ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
/*void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}*/

void ATank::AimAt(const FVector& Location)
{
	//TODO: Do actual aim
	UE_LOG(LogTemp, Display,
		TEXT("%s aiming at %s"),
		*this->GetName(), *Location.ToString()
	);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

