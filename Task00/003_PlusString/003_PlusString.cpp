// 003_PlusString.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int StringCount(const char* const _Str)
{
    int Count = 0;

    while (true)
    {
        if (_Str[Count] != 0)
        {
            Count += 1;
        }
        else
        {
            break;
        }
    }

    return Count;
}

const int IntMaxCount = 10;
const int ParameterInter = 8;

// 함수의 인자는 무조건 8바이트씩 떨어져 있다.
int MyPrintf(const char* const _Ptr, ...)
{
	__int64 FAdd = reinterpret_cast<__int64>(&_Ptr);

	int ChCount = 0;

	while (_Ptr[ChCount])
	{
		char Ch = _Ptr[ChCount];
		putchar(_Ptr[ChCount]);
		ChCount += 1;
	}

	return ChCount;
}

void PlusString(char* _Buffer, int _BufferSize, const char* const _Value0, const char* const _Value1)
{
    // _Value0의 자리수를 먼저 세기
    // _Buffer에 _Value0을 먼저 복사
    // _Buffer[_Value0]부터 _Value1을 복사

	int Count1 = StringCount(_Value0);
    int Count2 = StringCount(_Value1);
    int Index = 0;

    while (Index < Count1)
    {
        _Buffer[Index] = _Value0[Index];
        Index += 1;
    }

    while (Index < (Count1 + Count2))
    {
        _Buffer[Index] = _Value1[Index - Count1];
        Index += 1;
    }
}

int main()
{
    char Arr[100] = {};

    //PlusString(Arr, 100, "AAAA", "BBBB");
    //PlusString(Arr, 100, "AAA", "BBBB");
    PlusString(Arr, 100, "AAABC", "DDD");

    std::cout << "Hello World!\n";
}