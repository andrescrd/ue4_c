// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class UE4_UDEMY_API AGun : public AActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	FTimerHandle timerShootHandle;
	FTimerHandle timerStopShootHandle;

	FTimerHandle timerRotateHandle;
	FTimerHandle timerStopRotateHandle;

	UPROPERTY(EditAnywhere)
	float timeToShoot;

	UPROPERTY(EditAnywhere)
	float timeToStopShoot;

	UPROPERTY(EditAnywhere)
	float timeToRotate;

	UPROPERTY(EditAnywhere)
	float timeToStopRotate;

	UPROPERTY(EditAnywhere)
	FRotator rotatorVelocity;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> objectToSpawn;

	void Shoot();
	void StopShoot();

	void Rotate();
	void StopRotate();
};
