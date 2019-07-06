// SillikOne.


#include "CheckBoolVar.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UCheckBoolVar::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
	//Get BlackboardComponent
	const UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp){return false;}

	//Perform Boolean Variable Check
	return BlackboardComp->GetValueAsBool(bBoolVarToCheck.SelectedKeyName);
}

FString UCheckBoolVar::GetStaticDescription() const {
	FString ReturnDesc = Super::GetStaticDescription();
	ReturnDesc += "\n\n";
	ReturnDesc += FString::Printf(TEXT("%s: '%s'"), TEXT("Bool Variable to Check"), bBoolVarToCheck.IsSet() ? *bBoolVarToCheck.SelectedKeyName.ToString() : TEXT(""));
	return ReturnDesc;
}
