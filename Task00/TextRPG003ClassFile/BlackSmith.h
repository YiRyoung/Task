#pragma once
#include "Zone.h"
#include "Player.h"

class BlackSmith
{
public:
	// 안넣어주면 생성이 안되.
	//BlackSmith(UZone& _ParentZone)
	//	: ParentZone(_ParentZone)
	//{

	//}

	void InPlayer(class UPlayer& _Player/*, int& Result*/);

	inline void SetParent(class UZone* _ParentZone)
	{
		ParentZone = _ParentZone;
	}

	bool IsMaxEquip(class UPlayer& _Player);

	void PrintMaxEquip();

	void ReinforceEquip(class UPlayer& _Player);

private:
	// class UZone& ParentZone;

	class UZone* ParentZone = nullptr;
};

