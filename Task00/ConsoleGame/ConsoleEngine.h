#pragma once
#include "ConsoleWindow.h"
#include "Player.h"

class ConsoleEngine
{
	// void Update(); // 움직인다.
	// void Move(); // 움직인다.
public:
	static void Start();

	static FIntPoint GetWindowSize()
	{
		return WindowSize;
	}

	static UConsoleWindow& GetWindow()
	{
		return Window;
	}

private:
	ConsoleEngine();

	// 선언만 있고 실체는 존재하지 않기 때문에
	// 외부기호 오류가 뜬다.
	static FIntPoint WindowSize;
	static UConsoleWindow Window;

	Player NewPlayer;

	// 2번 실행되지 않습니다.
	void BeginPlay(); // 움직인다.

	void Tick(); // 움직인다.
	void Render(); // 그린다.
};

