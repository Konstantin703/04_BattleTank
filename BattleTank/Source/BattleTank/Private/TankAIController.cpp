// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//auto ControlledTank = GetControlledTank();
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if (PlayerTank)
	{
		// TODO move to player

		//Aim towards player
		ControlledTank->AimAt(PlayerTank->GetTargetLocation());
		ControlledTank->Fire(); // TODO don't fire every frame
	}
}
