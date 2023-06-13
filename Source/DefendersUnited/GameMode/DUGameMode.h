// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "DUGameMode.generated.h"

namespace MatchState
{
	extern DEFENDERSUNITED_API const FName Cooldown;   // Match duration has been reached. Display winner and begin cooldown timer.
}

/**
 * 
 */
UCLASS()
class DEFENDERSUNITED_API ADUGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	ADUGameMode();
	virtual void Tick(float DeltaTime) override;
	virtual void PlayerEliminated(class ADUCharacter* ElimmedCharacter, class ADUPlayerController* VictimController, class ADUPlayerController* AttackerController);
	virtual void EnemyEliminated(class ADUEnemy* ElimmedEnemy, class ADUPlayerController* AttackerController);
	virtual void RequestRespawn(class ACharacter* ElimmedCharacter, AController* ElimmedController);
	virtual void RequestRemoveEnemy(class ADUEnemy* ElimmedEnemy);

	UPROPERTY(EditDefaultsOnly)
	float EnemySpawnTime = 5.f;

	float EnemySpawnTimer;

	UPROPERTY(EditDefaultsOnly)
	float WarmupTime = 10.f;

	UPROPERTY(EditDefaultsOnly)
	float MatchTime = 120.f;

	UPROPERTY(EditDefaultsOnly)
	float CooldownTime = 10.f;

	float LevelStartingTime = 0.f;

protected:
	virtual void BeginPlay() override;
	virtual void OnMatchStateSet() override;

private:
	void SpawnEnemy();

private:
	float CountdownTime = 0.f;
public:
	FORCEINLINE float GetCountdownTime() const { return CountdownTime; }
};
