// Fill out your copyright notice in the Description page of Project Settings.


#include "lore/Public/Character/LoreCharacterEnemy.h"


ALoreCharacterEnemy::ALoreCharacterEnemy()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALoreCharacterEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}


void ALoreCharacterEnemy::HighlightActor()
{
}

void ALoreCharacterEnemy::UnHighlightActor()
{
}