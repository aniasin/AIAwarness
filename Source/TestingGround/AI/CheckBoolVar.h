// SillikOne.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "CheckBoolVar.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUND_API UCheckBoolVar : public UBTDecorator
{
	GENERATED_BODY()
virtual FString GetStaticDescription() const override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "AI")
		FBlackboardKeySelector bBoolVarToCheck;

public:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
