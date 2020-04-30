
#include "MyPlayer.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

AMyPlayer::AMyPlayer()
{
    velocity = 100;
    velocityRotation = 90;
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent *inputComponent)
{
    InputComponent->BindAxis("Vertical", this, &AMyPlayer::VerticalAxis);
    InputComponent->BindAxis("Horizontal", this, &AMyPlayer::HorizontalAxis);

    InputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPlayer::ShootPressed);
    InputComponent->BindAction("Shoot", IE_Released, this, &AMyPlayer::ShootReleased);
}

void AMyPlayer::VerticalAxis(float value)
{
    float deltaTime = GetWorld()->GetDeltaSeconds();
    AddActorLocalOffset(FVector(value * velocity * deltaTime, 0, 0));
}

void AMyPlayer::HorizontalAxis(float value)
{
    float deltaTime = GetWorld()->GetDeltaSeconds();
    AddActorLocalRotation(FRotator(0, value * velocityRotation * deltaTime, 0));
}

void AMyPlayer::ShootPressed()
{
    GetWorldTimerManager().SetTimer(timerHandle, this, &AMyPlayer::Fire, 1, true);
}

void AMyPlayer::ShootReleased()
{
    GetWorldTimerManager().ClearTimer(timerHandle);
}

void AMyPlayer::Fire()
{
    GetWorld()->SpawnActor<AActor>(objectToSpawn, GetActorLocation(), GetActorRotation());
}