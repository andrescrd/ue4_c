// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UE4_UDEMY_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	AMyActor();

	UPROPERTY(EditAnywhere)
	FVector velocity;

	UPROPERTY(EditAnywhere)
	FRotator rotation;

	virtual void Tick(float deltaTime) override;
};
