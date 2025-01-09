// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LoreCharacterBase.h"
#include "Interface/EnemyInterface.h"
#include "LoreCharacterEnemy.generated.h"

UCLASS()
class LORE_API ALoreCharacterEnemy : public ALoreCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	ALoreCharacterEnemy();

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

protected:
	virtual void BeginPlay() override;
};
