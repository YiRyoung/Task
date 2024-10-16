#pragma once
#include <EngineCore/Actor.h>

class Board : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	static Board& GetBoard()
	{
		return *MainBoard;
	}

	char PickPos(FIntPoint _Pos);

	void DrawObstacle(FIntPoint _Pos);
	void EraseObstacle(FIntPoint _Pos);

private:
	Renderer* Render = nullptr;
	static Board* MainBoard;
};