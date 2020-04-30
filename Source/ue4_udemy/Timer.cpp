// Fill out your copyright notice in the Description page of Project Settings.

#include "Timer.h"
#include "TimerManager.h"

// Sets default values
ATimer::ATimer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	time = 0;
	velocityMultiplier = 1;
}

// Called when the game starts or when spawned
void ATimer::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(timerHandle, this, &ATimer::Timer, 1, true);
}

// Called every frame
void ATimer::Tick(float DeltaTime)
{
	AddActorLocalOffset(velocityBase * velocityMultiplier);
}

void ATimer::Timer()
{
	time++;
	velocityBase = velocityBase * velocityAdd;
}
