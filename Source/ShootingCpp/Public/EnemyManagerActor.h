// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManagerActor.generated.h"

UCLASS()
class SHOOTINGCPP_API AEnemyManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManagerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//1. �ð��� �帣�ٰ�
	//2. ���� ����ð��� �����ð��� �ʰ��ϸ�
	//3. �����忡�� ���� �����ؼ� ȭ��ǥ ��ġ�� ��ġ�ϰ�ʹ�.
	//4. ����ð��� 0���� �ʱ�ȭ �ϰ�ʹ�.
	// �ʿ� �Ӽ�
	// - ȭ��ǥ
	UPROPERTY(EditAnywhere)
	class UArrowComponent* arrowComp;
	// - �� ����
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEnemyActor> enemyFactory;
	// - ����ð�
	float currentTime;
	// - �����ð�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float makeTime = 1;

	void MakeEnemy();
};
