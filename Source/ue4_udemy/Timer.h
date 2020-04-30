// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Timer.generated.h"

UCLASS()
class UE4_UDEMY_API ATimer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATimer();

private:
	UPROPERTY(VisibleAnywhere)
	float time;

	UPROPERTY(EditAnywhere)	
	FVector velocityBase;
	
	UPROPERTY(EditAnywhere)	
	float velocityMultiplier;

	UPROPERTY(EditAnywhere)	
	float velocityAdd;

	FTimerHandle timerHandle;
	void Timer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
