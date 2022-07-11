// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TailActor.generated.h"

UCLASS()
class SHOOTINGCPP_API ATailActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATailActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	// �ܰ��� ����� StaticMeshComponent�� �����ϰ�ʹ�.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;
	// ������ �� ���� target�� nullptr�̶�� �÷��̾ ã�Ƽ� target�� �����ϰ�ʹ�.
	// ��ư��鼭 Ÿ���� ���� �̵��ϰ�ʹ�. P = P0 + vt
	// �ʿ�Ӽ�
	// - Ÿ��
	UPROPERTY(EditAnywhere)
	AActor* target = nullptr;
	// - �ӷ�
	UPROPERTY(EditAnywhere)
	float speed;
};
