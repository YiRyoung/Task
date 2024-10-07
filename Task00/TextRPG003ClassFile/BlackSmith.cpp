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
	printf_s("�ִ� ��ȭ �����Դϴ�!\n");
	printf_s("������ ���ư��ϴ�.\n");
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
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
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
			

			// Ȯ���� ���δ� 2���� 1
			// 1���� �𿩾� �Ѵ�. �÷��̾��� ��ȭ �ܰ� * 100
			// ���� ���� 5���� �����ϰ� �ִ�. �׷��� 500���� �￩�� �Ѵ�.
			// 1~5������ ���а� ����Ȯ���� ������.
			// �ٿ������ �ʴ´�.
			// 6~10������ �����ϸ� 1�� �ٿ�ȴ�.
			// 11~15�� 0���� �����ϸ� 0���� ��������.
			// 15�� �̻��̸� ��ȭ�� ���ϰ� �ؾ����Ѵ�.
			return;
		case '2':
			return;
		default:
			break;
		}
	}
}