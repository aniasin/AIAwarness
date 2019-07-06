// SillikOne.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FocusAtObject.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUND_API UFocusAtObject : public UBTTaskNode
{
	GENERATED_BODY()
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;
public:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector FocusKey;
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector bCanSeePlayer;

protected:
	virtual FString GetStaticDescription() const override;
};
