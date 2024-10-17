#include "Board.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>
#include <conio.h>

Board* Board::MainBoard = nullptr;

void Board::BeginPlay()
{
	Super::BeginPlay();

	BoardSize = ConsoleEngine::GetEngine().GetWindow()->GetScreenSize();

	Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ BoardSize.X, BoardSize.Y }, '*');
	Render->Active = false;
	MainBoard = this;
}

void Board::DrawObstacle(FIntPoint _Pos)
{
	char ch = PickPos(_Pos);
	Render->Active = true;
	Render->RenderImage.SetPixel(_Pos, '@');
}

void Board::EraseObstacle(FIntPoint _Pos)
{
	Render->RenderImage.SetPixel(_Pos, '*');
}

char Board::PickPos(FIntPoint _Pos)
{
	return Render->RenderImage.GetPixel(_Pos.X, _Pos.Y);
} 

void Board::Tick()
{
	
}