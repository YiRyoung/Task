// 004_ClassSize.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test
{
    // 가상의 메모리(최소크기 -> 1)를 채워준다.
    // char Test;
};

int main()
{
    // 아무런 맴버변수도 없는 클래스는 사이즈가 얼마일까요?
    // 그리고 왜 그럴까요를 알아내보세요.

    int ClassSize = sizeof(Test);

    // 포인터 문법의 경우 문제가 발생하게 됨.
    // -> 그래서 최소크기를 0이 아닌 1로 잡아서 보장해주기로 함.
    // virtual? 
}