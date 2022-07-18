// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

//class UStaticMeshComponent; // ���漱��

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

	// ������, �������� �Է°��� �����ϰ�ʹ�.
	// ��ư��鼭 �Էµ� �� ���� ������ ������ �����
	// P = P0 + vt�� �̿��ؼ� �̵��ϰ�ʹ�.
	float h;
	float v;
	float speed = 500;


	void OnAxisHorizontal(float value);
	void OnAxisVertical(float value);

	// Fire��ư�� �������� �Ѿ˰��忡�� �Ѿ��� ���� �ѱ� ��ġ�� ��ġ�ϰ�ʹ�.
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABulletActor> bulletFactory;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* firePosition;

	void OnActionFire();

};
