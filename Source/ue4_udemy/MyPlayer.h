#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPlayer.generated.h"

UCLASS()
class UE4_UDEMY_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	AMyPlayer();

public:
	FTimerHandle timerHandle;

	UPROPERTY(EditAnywhere)
	float timeToShoot;
	UPROPERTY(EditAnywhere)
	float velocity;
	UPROPERTY(EditAnywhere)
	float velocityRotation;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> objectToSpawn;

	void SetupPlayerInputComponent(class UInputComponent *inputComponent);

	void VerticalAxis(float value);
	void HorizontalAxis(float value);
	void ShootPressed();
	void ShootReleased();
	void Fire();
};
