// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ue4_udemyGameModeBase.h"
#include "Engine/World.h"
#include "TimerManager.h"

Aue4_udemyGameModeBase::Aue4_udemyGameModeBase()
{
    PrimaryActorTick.bCanEverTick = true;
    maxTime = 10;
    counter = 0;
}

void Aue4_udemyGameModeBase::BeginPlay()
{
    GetWorldTimerManager().SetTimer(timerHandle, this, &Aue4_udemyGameModeBase::Timer, 1, true);
}

void Aue4_udemyGameModeBase::Tick(float deltaSecond)
{
    if (currentPoint >= maxPoint)
    {
        GetWorld()->ServerTravel("Level1");
    }
}

void Aue4_udemyGameModeBase::Timer()
{
    counter++;

    if (counter >= maxTime)
    {
        GetWorldTimerManager().ClearTimer(timerHandle);
        ChangeLevel();
    }
}

void Aue4_udemyGameModeBase::ChangeLevel()
{
    GetWorld()->ServerTravel("Level1");
}