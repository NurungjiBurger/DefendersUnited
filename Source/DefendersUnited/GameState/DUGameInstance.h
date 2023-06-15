// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DefendersUnited/Weapon/WeaponTypes.h"
#include "GameFramework/PlayerController.h"
#include "DUGameInstance.generated.h"

/**
 * 
 */

USTRUCT()
struct FPlayerStateData
{
	GENERATED_BODY()

	UPROPERTY()
	FString DUPlayerName;

	UPROPERTY()
	EWeaponType WeaponType;
};

UCLASS()
class DEFENDERSUNITED_API UDUGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	// �÷��̾� ���� ������ ������ ��
	TMap<APlayerController*, FPlayerStateData> PlayerStateMap;

	// �÷��̾� ���� ������ �����ϴ� �Լ�
	void SavePlayerState(APlayerController* PlayerController);

	// ����� �÷��̾� ���� ������ �����ϴ� �Լ�
	void ApplyPlayerState(APlayerController* PlayerController);
	
	// �� ��ȯ �� ȣ��Ǵ� �Լ�
	void ServerTravelToNewMap();

	// �� ��ȯ �� ȣ��Ǵ� �Լ�
	void AfterServerTravelToNewMap();
};
