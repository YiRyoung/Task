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
	CheckBoard();
	
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

	IsCheck();
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
	else if (GetNextBlock() == '@')	// 밑에 블럭이 있는지
	{
		FIntPoint TempPos = GetActorLocation();

		SetActorLocation({ 0, 0 });
		Board::GetBoard().DrawObstacle({ TempPos.X, TempPos.Y });
	}
}

char Block::GetBlock(FIntPoint _Pos)
{
	return Board::GetBoard().PickPos(_Pos);
}

char Block::GetNextBlock()
{
	return Board::GetBoard().PickPos({ GetActorLocation().X, ((GetActorLocation().Y + 1)) });
}

bool Block::CheckLine(int _y)
{
	int count = 0;
	for (int i = 2; i >= 0; i--)
	{
		FIntPoint CurPos = { i, _y };
		if (GetBlock(CurPos) == '@')
		{
			count++;
		}
	}

	if (count == 3)
	{
		return true;
	}
	return false;
}

void Block::EraseLine(int _y)
{
	for (int k = 0; k < 3; k++)
	{
		FIntPoint ErasePos = { k, _y };
		Board::GetBoard().EraseObstacle(ErasePos);
	}
}


void Block::DownBoard()
{
	for (int i = 3; i > 0 ; i--)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (j == 0 && i == 0)
			{
				continue;
			}
			FIntPoint CurPos = { j, i };
			if (GetBlock(CurPos) == '@' && GetNextBlock() == '*')
			{
				Board::GetBoard().DrawObstacle({ j, (i + 1) });
				Board::GetBoard().EraseObstacle(CurPos);
			}
		}
	}
}
void Block::CheckBoard()
{
	for (int i = 4; i >= 0; i--)
	{
		// 한 줄씩 확인
		if (CheckLine(i))
		{
			EraseLine(i);

			// 블럭 재배치
			DownBoard();
		}
			
		return;
	}
}