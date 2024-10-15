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

// ȭ���򰡿� �̳༮�� ������
// �Ϲ����� ���ӿ���

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
	// �Ǵٸ� ����Ʈ�� ������ �Ѵ�.
	ActorVector BulletVector;
	static Player* MainPlayer;
};

