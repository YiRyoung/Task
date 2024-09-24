// TextRpg000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

const int LINECOUNT = 50;

const int NAMELEN = 10;

// 절차지향 
// 어떠한 현실적인 개념을 컴퓨터 세계로 끌고 들어온다.
// 상태와 
int PlayerAttMin = 0;
int PlayerAtt = 0;
int PlayerHp = 0;
int PlayerSpeed = 10;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
int MonsterSpeed = 10;
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
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    // char[100] = 300번지
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
    PlayerSpeed = _Speed;
}

// 모든 문법은 코드를 덜치기 위해서 발전해왔습니다.
void CreateMonster(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
    MonsterSpeed = _Speed;
}

void StatusRender(const char* _Name, int _Att, int _HP)
{
    printf_s("%s Status", _Name);
    int nameLineCount = LINECOUNT - strlen(_Name) - strlen(" Status");
    for (int i = 0; i < nameLineCount; i += 1)
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

// 편의를 위해서 랩핑했다고 한다.
void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

// 클래스의 필요성
// 함수는 다양한 상황에서 쓸수있게 만들수록 좋다.
// 함수는 작은 기능을 많이 만들고 
// 함수는 한번에 1가지 일을 할수록 좋다.
// 로직과 랜더를 분리해야 한다.
void DamageRender(const char* const _AttName, const char* const _DefName, int _Att)
{
    // 랜더링
    printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);
}

void DamageLogic(int& _DefHp, int _Att)
{
    _DefHp -= _Att;
}

void SpeedCheckRender(const char* const _Name)
{
    printf_s("%s 의 선공입니다\n", _Name);
}

int CalSpeed(int _Speed)
{
    return rand() % _Speed;
}


int main()
{
    // char Test0[100] = "Player";
    /*char Test1[50] = Test0;
    Test1 = Test0*/;

    // 선공과 후공을 만드세요.
    CreatePlayer("1", 10, 100, 20);
    CreateMonster("Orc", 10, 100, 10);

    // 플레이어는 0~19
    // 몬스터는 0~9
    // 플레이어와 몬스터는 각자 난수로 자신의 현재 스피드 능력
    // 시작하기 전에 몬스터와 플레이어는 서로 현재 속력을 뽑아낸다.
    // 더 높은 쪽이 먼저 공격한다.

    srand(time(0));

    while (true)
    {
        // 화면 전체를 지워라.
        // 콘솔창에 다른 프로그램를 실행해주는 프로그램
        system("cls");

        char Input = ' ';

        int CurPlayerSpeed = CalSpeed(PlayerSpeed);
        int CurMonsterSpeed = CalSpeed(MonsterSpeed);


        PlayerStatusRender();
        MonsterStatusRender();
        Input = _getch();

        system("cls");
        // 데미지 주고
        // 플레이어가 몬스터보다 빠르다면
        // 플레이어가 먼저 데미지를 준다.
        if (CurPlayerSpeed > CurMonsterSpeed)
        {
            DamageLogic(MonsterHp, PlayerAtt);
            // 다시 다 출력
            PlayerStatusRender();
            MonsterStatusRender();
            SpeedCheckRender(PlayerName);
            DamageRender(PlayerName, MonsterName, PlayerAtt);
            Input = _getch();

            system("cls");
            DamageLogic(PlayerHp, MonsterAtt);
            // 다시 다 출력
            PlayerStatusRender();
            MonsterStatusRender();
            SpeedCheckRender(PlayerName);
            DamageRender(PlayerName, MonsterName, PlayerAtt);
            DamageRender(MonsterName, PlayerName, MonsterAtt);
        }
        else 
        {
            DamageLogic(PlayerHp, MonsterAtt);
            // 다시 다 출력
            PlayerStatusRender();
            MonsterStatusRender();
            SpeedCheckRender(MonsterName);
            DamageRender(MonsterName, PlayerName, MonsterAtt);
            Input = _getch();

            system("cls");
            DamageLogic(MonsterHp, PlayerAtt);
            // 다시 다 출력
            PlayerStatusRender();
            MonsterStatusRender();
            SpeedCheckRender(MonsterName);
            DamageRender(MonsterName, PlayerName, MonsterAtt);
            DamageRender(PlayerName, MonsterName, PlayerAtt);
        }
        Input = _getch();
    }

}
