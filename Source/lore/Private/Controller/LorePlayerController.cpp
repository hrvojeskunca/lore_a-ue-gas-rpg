// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/LorePlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interface/EnemyInterface.h"

ALorePlayerController::ALorePlayerController()
{
	bReplicates = true;
}

void ALorePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	SetupInputContext();
	SetupInputModeAndMousePreferences();
}

void ALorePlayerController::SetupInputContext() const
{
	check(LoreMovementContext);
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(LoreMovementContext, 0);
	}
}

void ALorePlayerController::SetupInputModeAndMousePreferences()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeGameAndUI;
	InputModeGameAndUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeGameAndUI.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeGameAndUI);
}

void ALorePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ALorePlayerController::Move);
}

void ALorePlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector2D = InputActionValue.Get<FVector2D>();
	const FRotator YawRotation(0.0f, GetControlRotation().Yaw, 0.0f);

	const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(Forward, InputAxisVector2D.Y);
		ControlledPawn->AddMovementInput(Right, InputAxisVector2D.X);
	}
}

void ALorePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void ALorePlayerController::CursorTrace()
{
	FHitResult CursorTraceHitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorTraceHitResult);
	if (!CursorTraceHitResult.bBlockingHit) return;

	LastActor = CurrentActor;
	CurrentActor = CursorTraceHitResult.GetActor();

	if (LastActor == nullptr)
	{
		if (CurrentActor != nullptr)
		{
			CurrentActor->HighlightActor();
		}
	}
	else
	{
		if (CurrentActor == nullptr)
		{
			LastActor->UnHighlightActor();
		}
		else
		{
			if (LastActor != CurrentActor)
			{
				LastActor->UnHighlightActor();
				CurrentActor->HighlightActor();
			}
		}
	}
}