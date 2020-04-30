// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun2.generated.h"

UCLASS()
class UE4_UDEMY_API AGun2 : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGun2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

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
