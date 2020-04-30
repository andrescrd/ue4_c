// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"
#include "Engine/World.h"
#include "TimerManager.h"

void AGun::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(timerStopShootHandle, this, &AGun::StopShoot, timeToStopShoot);
	GetWorldTimerManager().SetTimer(timerShootHandle, this, &AGun::Shoot, timeToShoot, true);
}

void AGun::Shoot()
{
	FVector pos = GetActorLocation();
	FRotator rot = GetActorRotation();
	GetWorld()->SpawnActor<AActor>(objectToSpawn, pos, rot);
}

void AGun::StopShoot()
{
	GetWorldTimerManager().ClearTimer(timerShootHandle);

	GetWorldTimerManager().SetTimer(timerRotateHandle, this, &AGun::Rotate, timeToRotate, true);
	GetWorldTimerManager().SetTimer(timerStopRotateHandle, this, &AGun::StopRotate, timeToStopRotate);
}

void AGun::Rotate()
{
	AddActorLocalRotation(rotatorVelocity);
}

void AGun::StopRotate()
{
	GetWorldTimerManager().ClearTimer(timerRotateHandle);

	GetWorldTimerManager().SetTimer(timerStopShootHandle, this, &AGun::StopShoot, timeToStopShoot);
	GetWorldTimerManager().SetTimer(timerShootHandle, this, &AGun::Shoot, timeToShoot, true);
}