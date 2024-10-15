#pragma once
#include "ConsoleImage.h"
#include "Actor.h"
#include "ActorVector.h"

//class AActor
//{
//	FIntPoint Location;
//};
//
//class Monster
//{
//	
//};

// 화면어딘가에 이녀석이 랜더링
// 일반적인 게임엔진

class Player : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;
	static Player* GetMainPlayer()
	{
		return MainPlayer;
	}

	const ActorVector& GetBulletVector()
	{
		return BulletVector;
	}

private:
	// 또다른 리스트를 가지게 한다.
	ActorVector BulletVector;
	static Player* MainPlayer;
};

