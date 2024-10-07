#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>

bool BlackSmith::IsMaxWeaponLv(class UPlayer& _Player)
{
	if (_Player.GetEquipAtt() >= 15)
	{
		return true;
	}
	return false;
}

void BlackSmith::PrintMaxWeapon()
{
	printf_s("최대 강화 상태입니다!\n");
	printf_s("마을로 돌아갑니다.\n");
	_getch();
}

void BlackSmith::ReinforceWeapon(class UPlayer& _Player)
{
	int Random = rand() % 2;
	int CurrentGold = _Player.GetGold();
	int CurrentAtt = _Player.GetEquipAtt();
	int ReinforceCost = (_Player.GetEquipAtt() * 100);
	int Result = CurrentGold - ReinforceCost;
	_Player.SetGold(Result);

	if (0 == Result)
	{
		_Player.SetEquipAtt(CurrentAtt + 1);
	}
	else
	{
		if (CurrentAtt > 5 && CurrentAtt < 11)
		{
			_Player.SetEquipAtt(CurrentGold - 1);
		}
		else if (CurrentAtt > 10 && CurrentAtt < 15)
		{
			_Player.SetEquipAtt(0);
		}
	}
}

void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("부모존이 세팅되지 않았습니다");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. 강화\n";
		std::cout << "2. 나간다\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':

			if (IsMaxWeaponLv(_Player))
			{
				PrintMaxWeapon();
				return;
			}

			ReinforceWeapon(_Player);
			

			// 확률은 전부다 2분의 1
			// 1돈이 깎여야 한다. 플레이어의 강화 단계 * 100
			// 내가 현재 5강에 도전하고 있다. 그러면 500원씩 깍여야 한다.
			// 1~5까지는 실패가 실패확률은 있지만.
			// 다운되지는 않는다.
			// 6~10까지는 실패하면 1씩 다운된다.
			// 11~15는 0으로 실패하면 0으로 떨어진다.
			// 15강 이상이면 강화를 못하게 해야해한다.
			return;
		case '2':
			return;
		default:
			break;
		}
	}
}