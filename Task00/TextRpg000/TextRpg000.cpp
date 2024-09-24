// TextRpg000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

const int LINECOUNT = 50;

const int NAMELEN = 10;

// 절차지향 
// 어떠한 현실적인 개념을 컴퓨터 세계로 끌고 들어온다.
// 상태와 
int PlayerAtt = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
char MonsterName[NAMELEN] = "NONE";

// 아주 중요한
void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
    for (int i = 0; i < _BufferSize; i += 1)
    {
        _Arr[i] = 0;
    }

    // C스타일 글자 개수 세어주는 함수
    int Size = strlen(_Name);
    _Arr[0] = _Name[0];
    // strcpy_s()
    for (int i = 0; i < Size; i++)
    {
        _Arr[i] = _Name[i];
    }
}

// 함수는 그냥 자기가 만들고 싶으면 만드는 것이다.
// 전 많이 만들수록 좋아합니다.

// 행동
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp)
{
    // char[100] = 300번지
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
}

// 모든 문법은 코드를 덜치기 위해서 발전해왔습니다.
void CreateMonster(const char* const _Ptr, int _Att, int _Hp)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
}

void StatusRender(const char* _Name, int _Att, int _HP)
{
    printf_s("%s Status ", _Name);
    
    // %s의 글자수에 따라서 출력되는 -의 개수가 달라져야 함. 
    int StringSize = strlen(" Status ");
    int PrintSize = strlen(_Name) + StringSize;

    // 총 글자 수는 LINECOUNT가 되도록
    for (int i = 0; i < (LINECOUNT - PrintSize); i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");

    
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);

    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");

    // printf_s("---------------------------------------------------\n");
}

void PlayerStatusRender()
{
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

int main()
{
    // char Test0[100] = "Player";
    /*char Test1[50] = Test0;
    Test1 = Test0*/;

    CreatePlayer("1", 10, 100);
    CreateMonster("Orc", 10, 50);

    PlayerStatusRender();
    MonsterStatusRender();

    // printf_s("싸운다");
    // 나는 이걸 플레이어라고 생각할 겁니다.


}
