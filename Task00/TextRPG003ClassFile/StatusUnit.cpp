#include "StatusUnit.h"
#include <BaseSystem/EngineDebug.h>
#include <iostream>

void UStatusUnit::TopLine()
{
    // TopLine
    const char* Name = GetName();
    printf_s("%s Status", Name);
    int NameLan = static_cast<int>(strlen(Name));
    int StatusRand = static_cast<int>(strlen(" Status"));
    int nameLineCount = LINECOUNT - NameLan - StatusRand;
    for (int i = 0; i < nameLineCount; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
}

void UStatusUnit::BotLine()
{
    // BotLine
    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
}

void UStatusUnit::TextPrint()
{
    printf_s("���ݷ� : %d ~ %d\n", MinAtt, MaxAtt);
    printf_s("ü�� : %d\n", Hp);
}

void UStatusUnit::StatusRender()
{
    // ��Ӱ��迡�� �ڽ��� �����ϴµ�.
    // ���� �Լ��� ����Կ��� �ڽĵ鸶�� �ٸ� ������ �ؾ��Ҷ� ����ϴ� ����
    // virtual 
    
    // ������ �޴°� �����ؼ�.
    TopLine();
    TextPrint();
    BotLine();
    // �̹��� �ٽ�.
    // �̰͵� �ɰ��°� �´�.

}

