// Fill out your copyright notice in the Description page of Project Settings.

#include "Tramp.h"

void ATramp::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ATramp::OnOverlap);
}

void ATramp::OnOverlap(AActor* me, AActor* other)
{
	other->Destroy();
}
