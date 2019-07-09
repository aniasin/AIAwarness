// SillikOne.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "GuardAIController.generated.h"

DECLARE_MULTICAST_DELEGATE(FIsAiming);
/**
 *
 */
UCLASS()
class TESTINGGROUND_API AGuardAIController : public AAIController
{
	GENERATED_BODY()
private:
	UAIPerceptionComponent*    PerceptionComponent;
	UAISenseConfig_Sight* SightConfig;
	UAISenseConfig_Hearing* HearingConfig;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float SightRange = 2000;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float SightLoseRange = 2500;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float HearingRange = 1000;
	
	//Constructor
	AGuardAIController();

	UFUNCTION()
	void OnTargetPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus);
public:
	bool bCanSeePlayer = false;
	FVector LastKnownPlayerPosition;

	FIsAiming OnAim;
};