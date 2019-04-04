// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankTrack.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * Responsible for driving tracks
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForvard(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float Throw);
	
private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
	
};
