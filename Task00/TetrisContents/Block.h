#pragma once
#include <EngineCore/Actor.h>

class Block : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	char GetBlock(FIntPoint _Pos);
	char GetNextBlock();

	bool CheckLine(int y);

	void IsCheck();
	void CheckBoard();
	
	void EraseLine(int y);
	void DownBoard();
private:
};

