// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"

#include "TankAimingComponent.generated.h"

class UStaticMeshComponent;
class UTankBarrelComponent;
class UTankTurretComponent;

UCLASS(ClassGroup=(Tank), meta=(BlueprintSpawnableComponent))
class MYTANKBATTLEUNREAL_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Instanced)
	UTankBarrelComponent* Barrel = nullptr;
	UPROPERTY(Instanced)
	UTankTurretComponent* Turret = nullptr;

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	/*UFUNCTION(BlueprintCallable)
	class UStaticMeshComponent* GetBarrel() const { return Barrel; }*/
	UFUNCTION(BlueprintCallable)
	void SetBarrel(UTankBarrelComponent* BarrelMesh) { this->Barrel = BarrelMesh; }

	UFUNCTION(BlueprintCallable)
	void SetTurrel(UTankTurretComponent* TurretMesh) { this->Turret = TurretMesh; }

	void AimTowards(const FVector& WorldLocation, float LaunchSpeed);

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;

public:
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	/**
	 * Moves turret according to the specified aiming direction
	 */
	void MoveTurretTowards(const FVector& AimDirection);
};
