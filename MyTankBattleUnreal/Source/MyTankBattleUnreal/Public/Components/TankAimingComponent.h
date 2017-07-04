// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"

#include "TankAimingComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYTANKBATTLEUNREAL_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UStaticMeshComponent* Barrel = nullptr;

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimTowards(const FVector& WorldLocation);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION(BlueprintCallable)
	class UStaticMeshComponent* GetBarrel() const { return Barrel; }
	UFUNCTION(BlueprintCallable)
	void SetBarrel(UStaticMeshComponent* Barrel) { this->Barrel = Barrel; }
};
