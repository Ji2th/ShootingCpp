// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "ScoreUI.h"
#include <Components/TextBlock.h>

AShootingGameModeBase::AShootingGameModeBase()
{
	score = 0;
}

void AShootingGameModeBase::BeginPlay()
{
	// 태어날 때(BeginPlay) 점수UI공장에서 점수UI를 만들어서 보이게 하고싶다.
	auto ui = CreateWidget(GetWorld(), scoreUIFactory);
	scoreUI = Cast<UScoreUI>(ui);
	if (nullptr != scoreUI)
	{
		scoreUI->AddToViewport();
	}
}

void AShootingGameModeBase::AddScore(int amount)
{
	// score에 amount를 누적하고싶다.
	score += amount;

	// 점수를 UI로 표현하고싶다.

	scoreUI->textBlockScore->SetText(FText::AsNumber(score));
	UE_LOG(LogTemp, Warning, TEXT("score : %d"), score);
}
