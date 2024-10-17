#pragma once
#include <EngineCore/Actor.h>

class Block : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	const char GetBlock(FIntPoint _Pos);
	const char GetNextBlock();

	const bool CheckLine(FIntPoint _BoardSize, int y);

	void CheckObstacle(FIntPoint _BoardSize);
	void CheckBoard();
	
	void EraseLine(FIntPoint _BoardSize, int y);
	void DownBoard(FIntPoint _BoardSize);
private:
};

