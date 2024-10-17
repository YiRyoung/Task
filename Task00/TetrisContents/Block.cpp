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
	FIntPoint MaxSize = Board::GetBoard().GetBoardSize();

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

	CheckObstacle(MaxSize);
}

void Block::CheckObstacle(FIntPoint _BoardSize)
{
	FIntPoint TempPos = GetActorLocation();

	// 바닥에 닿았는지
	if ((GetActorLocation().Y + 1) == _BoardSize.Y)
	{
		SetActorLocation({ 0, 0 });
		Board::GetBoard().DrawObstacle({ TempPos.X, TempPos.Y });
	}
	else if (GetNextBlock() == '@')	// 밑에 블럭이 있는지
	{
		SetActorLocation({ 0, 0 });
		Board::GetBoard().DrawObstacle({ TempPos.X, TempPos.Y });
	}
}

const char Block::GetBlock(FIntPoint _Pos)
{
	return Board::GetBoard().PickPos(_Pos);
}

const char Block::GetNextBlock()
{
	return Board::GetBoard().PickPos({ GetActorLocation().X, ((GetActorLocation().Y + 1)) });
}

const bool Block::CheckLine(FIntPoint _BoardSize, int _y)
{
	int count = 0;

	for (int i = _BoardSize.X; i >= 0; i--)
	{
		FIntPoint CurPos = { i, _y };
		if (GetBlock(CurPos) == '@')
		{
			count++;
		}
	}

	if (count == _BoardSize.X)
	{
		return true;
	}
	return false;
}

void Block::EraseLine(FIntPoint _BoardSize, int _y)
{
	for (int k = 0; k < _BoardSize.X; k++)
	{
		FIntPoint ErasePos = { k, _y };
		Board::GetBoard().EraseObstacle(ErasePos);
	}
}


void Block::DownBoard(FIntPoint _BoardSize)
{
	for (int i = (_BoardSize.Y - 2); i > 0 ; i--)
	{
		for (int j = (_BoardSize.X - 1); j >= 0; j--)
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
	FIntPoint MaxSize = Board::GetBoard().GetBoardSize();

	for (int i = (MaxSize.Y - 1); i >= 0; i--)
	{
		// 한 줄씩 확인
		if (CheckLine(MaxSize, i))
		{
			EraseLine(MaxSize, i);

			// 블럭 재배치
			DownBoard(MaxSize);
		}
			
		return;
	}
}