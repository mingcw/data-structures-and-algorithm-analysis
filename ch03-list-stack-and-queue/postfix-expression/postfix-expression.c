#include <stdio.h>
#include "stack.h"

#define STRING_SIZE 81
#define NaN -1

int calcPostfixExpression(char expr[]);
bool isNumber(char ch);
int parseInt(char expr[], int i);
bool isOperator(char ch);
int operate(int a1, int a2, char symbol);

int main(void)
{
    char expr[] = "6 5 2 3 + 8 * + 3 + *";
    
    printf("%s = %d\n", expr, calcPostfixExpression(expr));
    return 0;
}

// ����һ���Ϸ��ĺ�׺���ʽ
int calcPostfixExpression(char expr[])
{
    Stack S;
    char output[STRING_SIZE] = {'\0'}, ch;
    int i = 0, result;

    S = createStack();
    while ((ch = expr[i]) != '\0')
    {
        if (isNumber(ch))
        {
            push(S, parseInt(expr, i));
        }
        else if (isOperator(ch))
        {
            push(S, operate(pop(S), pop(S), ch));
        }
        i++;
    }
    result = pop(S);
    destroyStack(S);

    return result;
}

// �ж��ַ� ch �Ƿ������ַ�
bool isNumber(char ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}

// �� expr �ַ����� i λ��
// ��ʼ��ȡһ������
int parseInt(char expr[], int i)
{
    char ch;
    int number = 0, base = 1;

    while ((ch = expr[i]) != '\0' && ch != ' ' && isNumber(ch))
    {
        number += (ch - '0') * base;
        base *= 10;
        i++;
    }

    return number;
}

// �ж� ch �Ƿ���һ�������,
// ��֧�� + �� *
bool isOperator(char ch)
{
    if (ch == '+' || ch == '*')
        return true;
    else
        return false;
}

// �� a1 �� a2 Ӧ�� symbol �����,
// ����������
int operate(int a1, int a2, char symbol)
{
    if (isOperator(symbol))
    {
        switch (symbol)
        {
            case '+':
                a1 += a2;
                break;
            case '*':
                a1 *= a2;
                break;
            default:
                break;
        }
        return a1;
    }
    else
    {
        return NaN;
    }
}