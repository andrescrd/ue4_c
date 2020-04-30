
    #include "MyPlayer.h"
    #include "Components/InputComponent.h"
    #include "Engine/World.h"
    #include "TimerManager.h"
    #include "ue4_udemyGameModeBase.h"

    AMyPlayer::AMyPlayer()
    {
        velocity = 100;
        velocityRotation = 90;
        timeToShoot = 0.2f;
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
        GetWorldTimerManager().SetTimer(timerHandle, this, &AMyPlayer::Fire, timeToShoot, true);

        Aue4_udemyGameModeBase *gameMode = GetWorld()->GetAuthGameMode<Aue4_udemyGameModeBase>();
        gameMode->currentPoint += 20;
    }

    void AMyPlayer::ShootReleased()
    {
        GetWorldTimerManager().ClearTimer(timerHandle);
    }

    void AMyPlayer::Fire()
    {
        GetWorld()->SpawnActor<AActor>(objectToSpawn, GetActorLocation(), GetActorRotation());
    }