// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LorePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class IEnemyInterface;

struct FInputActionValue;

UCLASS()
class LORE_API ALorePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ALorePlayerController();

	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputMappingContext> LoreMovementContext;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> MoveInputAction;
	
	void SetupInputContext() const;
	void SetupInputModeAndMousePreferences();

	void Move(const FInputActionValue& InputActionValue);
	
	void CursorTrace();

	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> CurrentActor;
};
