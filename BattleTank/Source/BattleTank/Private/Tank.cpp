// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankMovementComponent.h"
#include "Components/InputComponent.h"
#include "TankPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MovementComponent = CreateDefaultSubobject<UTankMovementComponent>(TEXT("TankMovementComponent"));

}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;



}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	return DamageToApply;
}

void ATank::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	if (!ensure(PlayerInputComponent)) return;
	PlayerInputComponent->BindAxis("Forward", MovementComponent, &UTankMovementComponent::IntendMoveForward);
	PlayerInputComponent->BindAxis("TurnRight", MovementComponent, &UTankMovementComponent::IntendTurnRight);
	//PlayerInputComponent->BindAxis("Turn Right", this, 
}

void ATank::DestroyTank() {}
