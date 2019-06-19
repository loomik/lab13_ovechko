#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

//////////////////////////////////////////����������� ����/////////////////////////////////////////////

union char_ /// ����� �������� � 8 ����
{
    char bit;
    struct {
        unsigned char bit7: 1;
        unsigned char bit6: 1;
        unsigned char bit5: 1;
        unsigned char bit4: 1;
        unsigned char bit3: 1;
        unsigned char bit2: 1;
        unsigned char bit1: 1;
        unsigned char bit0: 1;
    };
};

//////////////////////////////////////////////////////////////////////////////////////////////

struct hex
{
    union char_ ch[4];
};

///////////////////////////////////�������� �������/////////////////////////////////////////////////

struct hex enter(); /// ����
struct hex shift(struct hex , int, int); /// ��������������

/////////////////////////////////main//////////////////////////////////////////////////

int main() {
    SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
    struct hex code;
    code = enter();
    printf("������ ����������������� ����: 1) %3x 2) %3x 3) %3x 4) %3x\n", code.ch[0].bit,
            code.ch[1].bit, code.ch[2].bit, code.ch[3].bit);
    int N, k;
    printf("���� � �������� �������: 1) %d%d%d%d%d%d%d%d 2) %d%d%d%d%d%d%d%d"
           " 3) %d%d%d%d%d%d%d%d 4) %d%d%d%d%d%d%d%d\n", code.ch[0].bit0, code.ch[0].bit1,
           code.ch[0].bit2, code.ch[0].bit3, code.ch[0].bit4, code.ch[0].bit5, code.ch[0].bit6,
           code.ch[0].bit7, code.ch[1].bit0, code.ch[1].bit1, code.ch[1].bit2, code.ch[1].bit3,
           code.ch[1].bit4, code.ch[1].bit5, code.ch[1].bit6, code.ch[1].bit7, code.ch[2].bit0,
           code.ch[2].bit1, code.ch[2].bit2, code.ch[2].bit3, code.ch[2].bit4, code.ch[2].bit5,
           code.ch[2].bit6, code.ch[2].bit7, code.ch[3].bit0, code.ch[3].bit1, code.ch[3].bit2,
           code.ch[3].bit3, code.ch[3].bit4, code.ch[3].bit5, code.ch[3].bit6, code.ch[3].bit7);
    printf("������� ����� ����, ������� �� ������ ������������� (��� 1, ��� 2, ��� 3, ��� 4): ");
    scanf("%d", &k);
    printf("������� �� ����� ���-�� ������ ���������� �����: ");
    scanf("%d", &N);
    N = N % 8;
    code = shift(code, N, k);
    printf("��������������� ����������������� ����: 1) %3x 2) %3x 3) %3x 4) %3x\n", code.ch[0].bit,
           code.ch[1].bit, code.ch[2].bit, code.ch[3].bit);
    printf("���� � �������� �������: 1) %d%d%d%d%d%d%d%d 2) %d%d%d%d%d%d%d%d"
           " 3) %d%d%d%d%d%d%d%d 4) %d%d%d%d%d%d%d%d\n", code.ch[0].bit0, code.ch[0].bit1,
           code.ch[0].bit2, code.ch[0].bit3, code.ch[0].bit4, code.ch[0].bit5, code.ch[0].bit6,
           code.ch[0].bit7, code.ch[1].bit0, code.ch[1].bit1, code.ch[1].bit2, code.ch[1].bit3,
           code.ch[1].bit4, code.ch[1].bit5, code.ch[1].bit6, code.ch[1].bit7, code.ch[2].bit0,
           code.ch[2].bit1, code.ch[2].bit2, code.ch[2].bit3, code.ch[2].bit4, code.ch[2].bit5,
           code.ch[2].bit6, code.ch[2].bit7, code.ch[3].bit0, code.ch[3].bit1, code.ch[3].bit2,
           code.ch[3].bit3, code.ch[3].bit4, code.ch[3].bit5, code.ch[3].bit6, code.ch[3].bit7);
    return 0;
}

//////////////////////////////////�������/////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

struct hex enter() /// ����
{
    struct hex add;
    printf("������� 4 ���������������� �����");
    int i;
    printf("\n������: ");
    scanf("%x", &i);
    add.ch[0].bit = i;
    printf("������: ");
    scanf("%x", &i);
    add.ch[1].bit = i;
    printf("������: ");
    scanf("%x", &i);
    add.ch[2].bit = i;
    printf("\n���������: ");
    scanf("%x", &i);
    add.ch[3].bit = i;
    return add;
}

//////////////////////////////////////////////////////////////////////////////////////////////

struct hex shift(struct hex current, int N, int k) /// �������������� ����������������� ����
{
    if (k == 1)
        current.ch[0].bit = current.ch[0].bit << N;
    else if (k == 2)
        current.ch[1].bit = current.ch[1].bit << N;
    else if (k == 3)
        current.ch[2].bit = current.ch[2].bit << N;
    else if (k == 4)
        current.ch[3].bit = current.ch[3].bit << N;
    return current;
}

//////////////////////////////////////////////////////////////////////////////////////////////







