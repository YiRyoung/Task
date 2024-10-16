#include "Block.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <conio.h>

#include "Board.h"

void Block::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
}

void Block::Tick()
{
	Super::Tick();

	if (Board::GetBoard().Test1({ GetActorLocation().X, (GetActorLocation().Y + 1)
		}) == '@')
	{
		FIntPoint TempPos = GetActorLocation();
		SetActorLocation({ 0, 0 });
		Board::GetBoard().DrawObstacle({ TempPos.X, (TempPos.Y) });
	}

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
			if ((GetActorLocation().Y + 1) == 5)
			{
				FIntPoint TempPos = GetActorLocation();
				SetActorLocation({ 0, 0 });
				Board::GetBoard().DrawObstacle({TempPos.X, (TempPos.Y)});
			}
			break;
		//case 'T':
		//case 't':
			//Board::GetBoard().TestCode(this->GetActorLocation());
			// AddActorLocation(FIntPoint::DOWN);
			break;
		default:
			break;
		}

	}


}