// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tramp.generated.h"

UCLASS()
class UE4_UDEMY_API ATramp : public AActor
{
	GENERATED_BODY()

protected:	
	void BeginPlay() override;
	
public:
	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);
};
