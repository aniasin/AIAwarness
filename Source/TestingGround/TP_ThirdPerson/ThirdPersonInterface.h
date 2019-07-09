// SillikOne.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ThirdPersonInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UThirdPersonInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTINGGROUND_API IThirdPersonInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "TestingGround")
	bool EventAim();
};
