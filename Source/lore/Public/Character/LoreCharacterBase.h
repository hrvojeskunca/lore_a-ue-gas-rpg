// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LoreCharacterBase.generated.h"

UCLASS(Abstract)
class LORE_API ALoreCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ALoreCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Combat)
	TObjectPtr<UStaticMeshComponent> WeaponComponent;
};
