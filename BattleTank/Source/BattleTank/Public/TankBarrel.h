// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS( meta = (BlueprintSpawnableComponent), hidecategories = ("Collision") )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downaward movement, and =1 is max 
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category= "Setup")
	float MaxDegreesPerSecond = 10; // sensible default

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 40; 

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = 0; 
};
