// SillikOne.


#include "UpdateChaseService.h"
#include "Kismet/GameplayStatics.h"
#include "Classes/AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AI/GuardAIController.h"

UUpdateChaseService::UUpdateChaseService(const FObjectInitializer& ObjectInitializer){
	bNotifyBecomeRelevant = true;
	bNotifyCeaseRelevant = false;
}

void UUpdateChaseService::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory){
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) { return; }

	if (!PlayerKey.IsSet()) {
		// Retrieve player and fill array
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlayerClass, FoundActors);
		if (FoundActors[0]) {
			BlackboardComp->SetValueAsObject(PlayerKey.SelectedKeyName, FoundActors[0]);
		}
	}

}

void UUpdateChaseService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds){
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) { return; }

	// Get AIController
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController) { return; }
	AGuardAIController* GuardController = Cast<AGuardAIController>(AIController);

	// Update the blackboard with the value of bCanSeePlayer from GuardController
	BlackboardComp->SetValueAsBool(CanSeePlayerKey.SelectedKeyName, GuardController->bCanSeePlayer);

	// if the lasCanSee is different than CanSee then update LastKnownPosition & flip/flop Aim State
	if (GuardController->bCanSeePlayer != bLastCanSeePlayer) {
		BlackboardComp->SetValueAsVector(LastKnownPositionKey.SelectedKeyName, GuardController->LastKnownPlayerPosition);
	}
	bLastCanSeePlayer = GuardController->bCanSeePlayer;
	

	//Call to the parent TickNode
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}

FString UUpdateChaseService::GetStaticDescription() const{
	return FString::Printf(TEXT("%s: '%s'"), TEXT("Player Class"), PlayerClass ? *PlayerClass->GetName() : TEXT(""))
		.Append(FString::Printf(TEXT("\n%s: '%s'"), TEXT("PlayerKey"), PlayerKey.IsSet() ? *PlayerKey.SelectedKeyName.ToString() : TEXT("")))
		.Append(FString::Printf(TEXT("\n%s: '%s'"), TEXT("LastKnownPositionKey"), LastKnownPositionKey.IsSet() ? *LastKnownPositionKey.SelectedKeyName.ToString() : TEXT("")))
		.Append(FString::Printf(TEXT("\n%s: '%s'"), TEXT("CanSeePlayerKey"), CanSeePlayerKey.IsSet() ? *CanSeePlayerKey.SelectedKeyName.ToString() : TEXT("")));
}


