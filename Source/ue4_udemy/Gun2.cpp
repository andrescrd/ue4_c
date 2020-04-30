// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun2.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
AGun2::AGun2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGun2::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(timerShootHandle, this, &AGun2::Shoot, timeToShoot, true);
	GetWorld()->GetTimerManager().SetTimer(timerStopShootHandle, this, &AGun2::StopShoot, timeToStopShoot);
}

// Called every frame
void AGun2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGun2::Shoot()
{
	FVector pos = GetActorLocation();
	FRotator rot = GetActorRotation();

	GetWorld()->SpawnActor<AActor>(objectToSpawn, pos, rot);
}

void AGun2::StopShoot()
{
	GetWorld()->GetTimerManager().ClearTimer(timerShootHandle);

	GetWorld()->GetTimerManager().SetTimer(timerRotateHandle, this, &AGun2::Rotate, timeToRotate, true);
	GetWorld()->GetTimerManager().SetTimer(timerStopRotateHandle, this, &AGun2::StopRotate, timeToStopRotate);
}

void AGun2::Rotate()
{
	AddActorLocalRotation(rotatorVelocity);
}

void AGun2::StopRotate()
{
	GetWorld()->GetTimerManager().ClearTimer(timerRotateHandle);
	Super::Destroy();
}