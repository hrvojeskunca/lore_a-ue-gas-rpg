// Fill out your copyright notice in the Description page of Project Settings.


#include "lore/Public/Character/LoreCharacterPlayer.h"


// Sets default values
ALoreCharacterPlayer::ALoreCharacterPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALoreCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALoreCharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ALoreCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

