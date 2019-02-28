// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AIControlledTank = GetControlledTank();
	if (AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possesed a tank: %s"), *AIControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AIController not possesing a tank"));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

