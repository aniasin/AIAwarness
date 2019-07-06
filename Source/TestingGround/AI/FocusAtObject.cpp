// SillikOne.


#include "FocusAtObject.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"


EBTNodeResult::Type UFocusAtObject::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	
	auto PawnAI = OwnerComp.GetAIOwner();
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	// Check if Pawn can see Player
	if (!BlackboardComp->GetValueAsBool(bCanSeePlayer.SelectedKeyName)) { return EBTNodeResult::Aborted; }

	// Set NPC Focus Location
	AActor* ObjectToFocus = (GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!ObjectToFocus) { return EBTNodeResult::Aborted; }
	auto PerceptionComp = PawnAI->GetAIPerceptionComponent();

	PawnAI->SetFocus(ObjectToFocus);
	BlackboardComp->SetValueAsObject(FocusKey.SelectedKeyName, ObjectToFocus);

	return EBTNodeResult::Succeeded;
}

FString UFocusAtObject::GetStaticDescription() const {
	return FString::Printf(TEXT("\n%s: '%s'"), TEXT("Object to Focus"), FocusKey.IsSet() ? *FocusKey.SelectedKeyName.ToString() : TEXT(""));
}
