// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ue4_udemyGameModeBase.generated.h"
/**
 * 
 */
UCLASS()
class UE4_UDEMY_API Aue4_udemyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	int counter;

protected:
	virtual void BeginPlay() override;

public:
	FTimerHandle timerHandle;

	UPROPERTY(EditAnywhere)
	float maxTime;

	UPROPERTY(VisibleAnywhere)
	float currentPoint;

	UPROPERTY(EditAnywhere)
	float maxPoint;

	Aue4_udemyGameModeBase();
	void Tick(float deltaSecond) override;

	void Timer();
	void ChangeLevel();
};
