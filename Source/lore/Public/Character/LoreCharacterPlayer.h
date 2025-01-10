// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LoreCharacterBase.h"
#include "LoreCharacterPlayer.generated.h"

UCLASS()
class LORE_API ALoreCharacterPlayer : public ALoreCharacterBase
{
	GENERATED_BODY()

public:
	ALoreCharacterPlayer();

protected:
	virtual void BeginPlay() override;

private:
	void SetDefaultCharacterMovement();
};
