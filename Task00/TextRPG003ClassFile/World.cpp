#include "World.h"
#include "FightZone.h"
#include "Town.h"
#include <conio.h>


void UWorld::InPlayer(class UPlayer& _Player)
{
	char InputName[100] = {0,};

	while (true)
	{
		system("cls");

		std::cout << "�̸��� �����ּ���" << std::endl;
		std::cin >> InputName;
		printf_s("����� �̸��� %s�Դϴ�. �����Ͻðڽ��ϱ�?\n", InputName);
		bool IsEnd = false;
		bool ReName = false;

		while (!ReName)
		{
			printf_s("a. ����\n");
			printf_s("b. ���Է�\n");
			int Select = _getch();
			switch (Select)
			{
			case 'a':
			case 'A':
				IsEnd = true;
				ReName = true;
				break;
			case 'b':
			case 'B':
				ReName = true;
				break;
			default:
				printf_s("�߸��� �����Դϴ�. �ٽ� �������ּ���\n");
				continue;
			}

		}
		if (true == IsEnd)
		{
			break;
		}
	}

	// �������ʱ��� ���⼭ �� ������� ����
	// ������ ������ FightZone�� ��� �ȴ�.
	// ���� ��� �������� 
	
	// new�� �� ����� �ϴ°ų�?
	// 8�Ⱑ
	UTown TownZone;
	TownZone.SetName("�ʺ�����");

	// 10�Ⱑ
	UFightZone FightZone;
	FightZone.SetName("�ʺ������");

	while (true)
	{
		TownZone.InPlayer(_Player);
	}



}