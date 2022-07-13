// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

//class UStaticMeshComponent; // 전방선언

UCLASS()
class SHOOTINGCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp = nullptr;

	// 가로축, 세로축의 입력값을 저장하고싶다.
	// 살아가면서 입력된 두 축의 값으로 방향을 만들고
	// P = P0 + vt를 이용해서 이동하고싶다.
	float h;
	float v;
	float speed = 500;

	void OnAxisHorizontal(float value);
	void OnAxisVertical(float value);

};
