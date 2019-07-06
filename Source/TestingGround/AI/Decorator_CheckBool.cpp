// SillikOne.


#include "Decorator_CheckBool.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UDecorator_CheckBool::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
	//Get BlackboardComponent
	const UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) { return false; }

	//Perform Boolean Variable Check
	return BlackboardComp->GetValueAsBool(bBoolVarToCheck.SelectedKeyName);
}

FString UDecorator_CheckBool::GetStaticDescription() const {
	FString ReturnDesc = Super::GetStaticDescription();
	ReturnDesc += "\n\n";
	ReturnDesc += FString::Printf(TEXT("%s: '%s'"), TEXT("Bool to Check"), bBoolVarToCheck.IsSet() ? *bBoolVarToCheck.SelectedKeyName.ToString() : TEXT(""));
	return ReturnDesc;
}
