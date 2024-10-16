#include "Block.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>
#include <conio.h>

#include "Board.h"

void Block::BeginPlay()
{
	Super::BeginPlay();

	Renderer * Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
}

void Block::Tick()
{
	Super::Tick();

	IsCheck();
	CheckLine();
	
	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			AddActorLocation(FIntPoint::LEFT);
			break;
		case 'D':
		case 'd':
			AddActorLocation(FIntPoint::RIGHT);
			break;
		case 'W':
		case 'w':
			AddActorLocation(FIntPoint::UP);
			break;
		case 'S':
		case 's':
			AddActorLocation(FIntPoint::DOWN);
			break;
		default:
			break;
		}
	}

}

void Block::IsCheck()
{
	// 바닥에 닿았는지
	if ((GetActorLocation().Y + 1) == 5)
	{
		FIntPoint TempPos = GetActorLocation();
		SetActorLocation({ 0, 0 });
		Board::GetBoard().DrawObstacle({ TempPos.X, TempPos.Y });
	}
	else if (GetBlock() == '@')	// 밑에 블럭이 있는지
	{
		FIntPoint TempPos = GetActorLocation();

		SetActorLocation({ 0, 0 });
		Board::GetBoard().DrawObstacle({ TempPos.X, TempPos.Y });
	}
}

char Block::GetBlock()
{
	return Board::GetBoard().PickPos({ GetActorLocation().X, ((GetActorLocation().Y + 1)) });
}

void Block::CheckLine()
{
	for (int i = 0; i < 5; i++)
	{
		int Count = 0;

		for (int j = 0; j < 3; j++)
		{
			char ch = Board::GetBoard().PickPos({ j, i });
			if (ch == '@')
			{
				Count++;
			}
		}
		if (Count == 3)
		{
			for (int k = 0; k < 3; k++)
			{
				Board::GetBoard().EraseObstacle({ k, i });
			}
			return;
		}
	}
	// return false;
}