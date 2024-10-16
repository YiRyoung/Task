#pragma once
#include <EngineCore/Actor.h>

class Block : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

	char GetBlock();
	void IsCheck();
	void CheckLine();
private:
};

