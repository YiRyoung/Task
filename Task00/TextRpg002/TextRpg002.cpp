// TextRPG002inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <assert.h>


#define MSGASSERT(VALUE) MessageBoxA(nullptr, VALUE, "치명적 에러", MB_OK); assert(false);

const int LINECOUNT = 50;
const int NAMELEN = 20;


// 다중상속을 부정적으로 생각하는 사람이 많아요.
// 1. 다중상속을 제대로 못쓰니까.
// 2. 제대로 쓸줄 알아도 다른 사람들을 못믿으니까.

// 좀더 근본에 가까운 기능과 데이터들이 뭐냐를 판단하는 능력.
// 상속구조의 절대 금기.

class StatusUnit
{
public:
    void SetName(const char* const _Name)
    {
        if (NAMELEN <= strlen(_Name))
        {
            MSGASSERT("이름이 너무 깁니다");

            //// 아주 사소한 경고나 에러라도 무조건 없애고 갈겁니다.
            //MessageBoxA(nullptr
            //    , "이름이 너무 깁니다" // 메세지 박스에 뜨는 내용
            //    , "치명적 에러" // 메세지 박스에 뜨는 제목
            //    , MB_OK // ok만 존재하는 메세지 박스로 만들어라
            //);
            //assert(false);

            // 이 사태가 벌어졌다는것을 어떻게 인지할건가요?
            return;
        }

        strcpy_s(Name, _Name);
    }

protected:
    char Name[NAMELEN] = "NONE";
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;
    int Charm = 0;

    // 부모는 자식클래스가 뭔지 절대로 알아서는 안된다.
    //void Test(FightUnit& _Test)
    //{
    //}
};


class FightUnit : public StatusUnit
{
public:
    // void DamageLogic(int _Att)
    // class DamageData;

    // AttackLogic이라고 짓고

    //void AttackLogic(FightUnit& _DefUnit)
    //{
    //    _DefUnit.Hp -= MinAtt;
    //}

    // MinMax
    int GetDamage() const
    {
        // minAtt ~ MaxAtt 사이의 숫자가 리턴되는 함수를 만드세요.
        // return MinAtt + rand

        return MinAtt + rand() % (MaxAtt - MinAtt + 1);
    }

    // 클래스의 레퍼런스를 넣어주는것이 많은게 간단해 집니다.
    void DamageLogic(const int _Damage)
    {
        // _AttUnit => 나를 공격하려는 상대
        Hp -= _Damage;
    }

    void DamageRender(const FightUnit& _AttUnit, const int _Damage)
    {
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttUnit.GetName(), Name, _Damage);
    }

    const char* GetName() const
    {
        return Name;
    }

protected:


private:
};

// 컴포넌트 방식이라는 것과 차이가 거의 없다.
// 보통 상속구조와 컴포넌트 기반구조가 게임의 로직계를 지배하고 있다.
// 

class Player : public FightUnit
{
};

class Monster : public FightUnit
{

};


// 게임을 만들다보면
// 일반적인 로직클래스 Player
// 리소스 클래스 <= 
// 데이터 전담클래스가 <= 내부에 변수밖에 없다. 
// 맴버변수도 public을 사용합니다.

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Player NewPlayer;
    Monster NewMonster;
    NewPlayer.SetName("Player");
    NewMonster.SetName("Monster");

    char ch = ' ';

    while (true)
    {
        int MonsterDamage = NewMonster.GetDamage();
        NewMonster.DamageLogic(MonsterDamage);
        NewMonster.DamageRender(NewPlayer, MonsterDamage);
        //ch = _getch();
    }

    // NewPlayer.
}
