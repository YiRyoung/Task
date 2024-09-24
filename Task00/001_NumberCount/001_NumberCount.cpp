// 001_NumberCount.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 음수 안함
// 0 이외의 양수의 자릿수를 세자.
int NumberCount(int _Value)
{
    // /(나누기를 최대한) 연산을 사용하세요.
    int Result = 0;


    // 메모리 영역
    // 메모리영역 내부의 모든 비트가 0이면
    // 하나라도 0이 아니면 다 참
    while (_Value != 0)
    {
        _Value /= 10;
        Result += 1;
    }

    return Result;
}

// 0번째 : _Value / 10;
// 1번째 : _Value / 100;
// 2번째 : _Value / 1000;

// 해도 되고 안해도 됩니다.
// 내 기준으로 지금
// _Value 를 넣어주면 Buffer에 
// 숫자를 문자열로 만드는 함수.
const int IntMaxCount = 10;

void NumberToString(char* Buffer, int BufferSize, int _Value)
{
    int Count = NumberCount(_Value);

    int MulValue = 1;
    for (int i = 0; i < Count - 1; i += 1)
    {
        MulValue *= 10;
    }

    for (int i = 0; i < Count; i += 1)
    {
        // 12321
        int CurValue = _Value / MulValue;
        Buffer[i] = CurValue + '0';
        _Value -= CurValue * MulValue;
        MulValue /= 10;
    }

    return;
}

int main()
{
    // 5
    int Result0 = NumberCount(12358);
    // 4
    int Result1 = NumberCount(5258);
    // 7
    int Result2 = NumberCount(5258111);

    // 0은 영

    char Buffer[100] = { 0 };

    NumberToString(Buffer, 100, 3712);
    NumberToString(Buffer, 100, 12321);
    // Buffer == "3712"
}
