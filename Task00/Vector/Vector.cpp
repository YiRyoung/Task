// Vector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include "UVector.h"

// 자료구조는 2가지 메모리적 분류 공식은 아닙니다.
// 노드형태로 관리하는 자료구조와
// 배열형태로 관리하는 자료구조가 있다.

// vector 자료들을 배열형태로 관리합니다.

// 3가지 형태적 분류로 나눈다고 했습니다.
// 시퀀스 형태의 컨테이너(자료구조)
// 시퀀스 vector 
// 9 4 1 7 => 9417 for문 돌렸는데.
// 9 4 1 7 => 그냥 내가 넣어준대로 그대로 순환하는 자료구조가 시퀀스


// 연관 => 내가 넣어준 자료를 순회했더니 순서가 바뀌어 있는 자료구조를 연관 컨테이너라고 부르지
//         정려해주는 자료구조가 연관 컨테이너가 아니에요.
// 9 4 1 7 => 1 4 7 9 
// 9 4 1 7 => 7 4 1 9 

// 어뎁터 => 거의 안나옵니다. 추후 설명하겠습니다.
//           특수한 자신만의 규칙이 존재하면 어뎁터 queue stack이 있습니다.
//          사용하는 방법이 특수하면

// 직접 만든 벡터를 사용하는 일은 일단 없을 겁니다.
// 사후 관리가 너무 어렵고 짜증납니다.
// 이미 완성된 std::vector가 있고 개네가 아무리 느리고 비효율적이어도 그냥 쓸거에요.
// 다 외부라이브러리들이 훨씬 빠릅니다.
// std::vector보다 빠른 자료구조들이 github나 널려 있어요.
// 언리얼도 전부다 자기들이 만들었다. 
// 언리얼에서 std 자료구조는 사용하지 않는게 좋습니다.

class Skill
{

};

// 벡터는 정적 배열이 들어갈 위치에서 벡터를 사용합니다.
// std::vector<Skill> AllSkill;
// Skill AllSkill[200]


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    // 전혀 대학에서 배운건 이론위주로 배운다는게 뭐냐면?
    // 개념적인 특성에서 접근합니다.
    // 공간과 데이터를 분리합니다.
    // 10개의 자료를 넣고 싶다.

    // 0 1 2 3 4 5 6 7 8 9  => 자료
    // 이걸 시퀀스 형태로 보관해주는 어떠한 인터페이스가 => 자료구조
    
    // 대학
    
    // C++ => 클래스
    // template<typename DataType>
    // class Vector
    

    // vector의 핵심은
    // 공간과 데이터를 분리했다는 겁니다.
    // 0 1 2 3 4 5 6 7 8 9 => 10개의 자료가 있다.
    // [      40byte      ] => 10개의 공간

    // 공간이 0이다.
    // [] => 공간을 확장시켜야 합니다.
    // [0] => 공간을 만들고 확장하는게 배열형이기 때문에.
    
    // 이상태에서 1을 추가 넣고 싶다.
    // [0] => 기존
    // [??] => 새로운 2개의 데이터를 다 넣을수 있는 공간을 만듭니다.
    // [0?] => 기존 데이터를 복사한다.
    // [01] => 기존 데이터를 복사한다.

    // 가장 연산이 많이드는것이
    // 이론과 실제가 다른부분
    // 100의 공간을 만들려면 100의 시간이 걸린다고 표현한다.
    // 벡터를 사용할때는 어느정도의 최대
    // 정적 배열 대신 사용한다. 

    // std::Vector<int>
    // {
    //    int* = new int[Arrsize]
    // }
    // 
    // 공간을 나타내는 capacity() => 배열의크기
    // 자료를 나내트는 size() => 배열에 들어간 자료의 크기
    // 
    // 로 구분합니다.

    // 공간을 할당하고 다시는 할당하지 않는게 벡터를 사용하는 최고의 방법입니다.
    // 그리고 그냥 다 그렇게 씁니다.
    // 애초에 삭제를 하면 잘못사용했다 수준으로 생각합니다.

    {
        std::vector<int> stdvector;

        // [0][1][2][3]
        // [3][0][1][2]

        // stdvector[20] = 10;

        // 누가 이거 안하고 사용하는거 보면 지적할 겁니다.
        stdvector.reserve(100);
        stdvector.reserve(10);

        // 이녀석은 list 만들면서 배울겁니다.
        // stdvector.erase(5);

        // vector의 가장 좋은 사용법은 capacity가 최소한으로 변화하게 하는것이다.
        // 한번 변화하고 아예 변하지 않으면 최고 사용법으로 보면 된다.

        // stdvector.resize(10);

        for (int i = 0; i < 10; i++)
        {
            // 0개
            // capacity가 먼저 늘어난다.
            // i가 늘어난 공간에 추가되죠.
            // size도 늘어난다.
            stdvector.push_back(i);
            std::cout << "push : " << stdvector[i] << std::endl;
            std::cout << "capacity : " << stdvector.capacity() << std::endl;
            std::cout << "size     : " << stdvector.size() << std::endl;
        }

        stdvector.clear();

        std::cout << "claer after capacity : " << stdvector.capacity() << std::endl;
    }


    {
        UVector<int> stdvector;
        // stdvector[20] = 20;
        stdvector.reserve(10);

        for (int i = 0; i < 10; i++)
        {
            stdvector.push_back(i);
            std::cout << "push : " << stdvector[i] << std::endl;
            std::cout << "capacity : " << stdvector.capacity() << std::endl;
            std::cout << "size     : " << stdvector.size() << std::endl;
        }
    }

}
