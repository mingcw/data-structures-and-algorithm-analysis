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

// 计算一个合法的后缀表达式
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

// 判断字符 ch 是否数字字符
bool isNumber(char ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}

// 从 expr 字符串的 i 位置
// 开始提取一个整数
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

// 判断 ch 是否是一个运算符,
// 暂支持 + 和 *
bool isOperator(char ch)
{
    if (ch == '+' || ch == '*')
        return true;
    else
        return false;
}

// 对 a1 和 a2 应用 symbol 运算符,
// 返回运算结果
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