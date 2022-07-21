// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootingGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGCPP_API AShootingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AShootingGameModeBase();

	virtual void BeginPlay() override;
	// 점수처리를 하고싶다.'
	void AddScore(int amount);
	int score;

	// 태어날 때(BeginPlay) 점수UI공장에서 점수UI를 만들어서 보이게 하고싶다.
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UScoreUI> scoreUIFactory;

	class UScoreUI* scoreUI;
};
