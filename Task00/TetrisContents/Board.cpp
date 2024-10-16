#include "Board.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <conio.h>

Board* Board::MainBoard = nullptr;

void Board::BeginPlay()
{
	Super::BeginPlay();

	Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 3, 5 }, '*');
	MainBoard = this;
	Render->Active = false;
}

void Board::DrawObstacle(FIntPoint _Pos)
{
	Render->RenderImage.SetPixel(_Pos, '@');
	Render->Active = true;
}

char Board::PickBlock(FIntPoint _Pos)
{
	return Render->RenderImage.GetPixel(_Pos.X, _Pos.Y);
}

void Board::Tick()
{

}