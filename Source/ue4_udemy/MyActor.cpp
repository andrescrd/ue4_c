// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::Tick(float deltaTime)
{
	AddActorLocalOffset(FVector(1, 0, 0));
}