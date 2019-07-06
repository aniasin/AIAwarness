// SillikOne.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "Decorator_CheckBool.generated.h"

/**
 *
 */
UCLASS()
class TESTINGGROUND_API UDecorator_CheckBool : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()
		virtual FString GetStaticDescription() const override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "AI")
		FBlackboardKeySelector bBoolVarToCheck;

public:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
