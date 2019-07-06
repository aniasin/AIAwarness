// SilikOne.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseWaypointTask.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUND_API UChooseWaypointTask : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;
	
protected:
	UPROPERTY(VisibleAnywhere, Category = "Blackboard")
		FBlackboardKeySelector IndexKey;
	UPROPERTY(VisibleAnywhere, Category = "Blackboard")
		FBlackboardKeySelector WaypointKey;
	UPROPERTY(VisibleAnywhere, Category = "AI")
		FBlackboardKeySelector bBoolVarToCheck;

};
