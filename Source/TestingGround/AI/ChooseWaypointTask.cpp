// SilikOne.

#include "AI/ChooseWaypointTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/PatrolComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"

EBTNodeResult::Type UChooseWaypointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	// if Player is in view, abort
	bool bPlayerSeen = BlackboardComp->GetValueAsBool(bBoolVarToCheck.SelectedKeyName);
	if (bPlayerSeen) { return EBTNodeResult::Aborted; }

	// Get Patrol route stored in PatrolComponent
	APawn* AIPawn = OwnerComp.GetAIOwner()->GetPawn();
	UPatrolComponent* PatrolComponent = AIPawn->FindComponentByClass<UPatrolComponent>();
	if (!ensure(PatrolComponent)) { return EBTNodeResult::Failed;}
	TArray<AActor*> PatrolRoute = PatrolComponent->GetPatrolRoute();
	if (PatrolRoute.Num() == 0){return EBTNodeResult::Failed;}

	// Set next Patrol point on blackboard
	int32 IndexValue = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolRoute[IndexValue]);

	// Cycle through the patrol points
	int32 NewIndexValue = (IndexValue + 1) % PatrolRoute.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NewIndexValue);

	return EBTNodeResult::Succeeded;
};
//TODO override GetDescription to give feed back in BT