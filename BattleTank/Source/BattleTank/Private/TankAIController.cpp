// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Tank.h" // So we can implement OnDeath method

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();	
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		ATank* PossesedTank = Cast<ATank>(InPawn);
		if (!PossesedTank) { return; }
		PossesedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossesedTankDeath);
	}
}

void ATankAIController::OnPossesedTankDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	APawn* ControlledTank = GetPawn();
	
	if (!(PlayerTank && ControlledTank)) { return; }
	
	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);
	
	UTankAimingComponent* AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

	// Temporary desission
	float Shift = 100;
	FVector FireDestination = FVector(
		PlayerTank->GetTargetLocation().X + FMath::FRandRange(-Shift, Shift),
		PlayerTank->GetTargetLocation().Y + FMath::FRandRange(-Shift, Shift),
		PlayerTank->GetTargetLocation().Z + FMath::FRandRange(-Shift, Shift)
	);
	
	AimingComponent->AimAt(FireDestination);
	
	if (AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
	{
		AimingComponent->Fire();
		UE_LOG(LogTemp, Warning, TEXT("%s is firing at Player's location: %s"), *GetPawn()->GetName(), *PlayerTank->GetTargetLocation().ToString());

	}	
}
