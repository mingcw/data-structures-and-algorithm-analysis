#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

#define MAXSIZE 40
#define UNVALID -1

void infixToPostfix(char * infix, char * postfix);
static bool isNumber(char ch);
static bool isPrior(char a, char b);
static int getPriority(char ch);

int main(void)
{
    char * a = "1+2*3+(4*5+6)*7"; // 1 2 3 * + 4 5 * 6 + 7 * +
    char b[MAXSIZE], ch;
    int i = 0;

    infixToPostfix(a, b);
    while ((ch = b[i++]) != '\0')
        putchar(ch);
    
    return 0;
}

void infixToPostfix(char * infix, char * postfix)
{
    Stack S;
    char ch;

    S = createStack();

    while (*infix != '\0')
    {
        if (isNumber(*infix))
        {
            *postfix++ = *infix++;
        }
        else if (*infix == ')')
        {
            while (!isEmpty(S) && (ch = pop(S)) != '(')
                *postfix++ = ch;
            infix++; // 字符指针前进一步！！！
        }
        else if (*infix == '(')
        {
            push(S, *infix++);
        }
        else
        {
            while (!isEmpty(S) && top(S) != '(' && !isPrior(*infix, top(S))) // 在循环弹出较优先的栈元素时，左圆括号不能弹出，除非遇到右圆括号！！！
                *postfix++ = pop(S);
            push(S, *infix++);
        }
    }

    while (!isEmpty(S))
        *postfix++ = pop(S);
    *postfix = '\0';

    destroyStack(S);
}

static bool isNumber(char ch)
{
    return ch >= '0' && ch <= '9';
}

static bool isPrior(char a, char b)
{
    return getPriority(a) - getPriority(b) > 0;
}

static int getPriority(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case ')':
            return 99;
        default:
            return UNVALID;
    }
}
