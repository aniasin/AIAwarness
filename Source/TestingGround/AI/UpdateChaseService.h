// SillikOne.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "UpdateChaseService.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUND_API UUpdateChaseService : public UBTService
{
	GENERATED_BODY()
	UUpdateChaseService(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector CanSeePlayerKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector PlayerKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector LastKnownPositionKey;

	UPROPERTY(EditAnywhere, Category = "PlayerClass")
	TSubclassOf<AActor> PlayerClass;

protected:
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual FString GetStaticDescription() const override;

private:
	bool bLastCanSeePlayer;
	
};
