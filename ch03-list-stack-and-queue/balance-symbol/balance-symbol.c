#include <stdio.h>
#include <string.h>
#include "stack.h"

bool isBalance(char * str);
static bool isPair(char open, char close);

int main(void)
{
    char balance[] = "This (is a [demo {for showi}ng a e]xample called b)a[l]ance-symbol of stack.";
    char unbalance1[] = "Thi(s is [an inv)alida]te string.";
    char unbalance2[] = "Thi(s is [an inva]lida)te {string.";

    printf("First string is %s.\n", isBalance( balance ) ? "balance" : "unbalance");
    printf("First string is %s.\n", isBalance(unbalance1) ? "balance" : "unbalance");
    printf("First string is %s.\n", isBalance(unbalance2) ? "balance" : "unbalance");

    return 0;
}

// 检查字符串的所有括号是否全部闭合
bool isBalance(char * str)
{
    Stack S;
    bool balance = true;
    int i = 0;
    char ch;

    S = createStack();
    while ((ch = str[i]) != '\0')
    {
        switch (ch)
        {
            // 遇到开放符号压入栈中
            case '(':
            case '[':
            case '{':
                push(S, ch);
                break;

            // 遇到闭合括号，如果是「空栈」或与栈顶弹出的开放符号「不成对」则报错
            case ')':
            case ']':
            case '}':
                if (isEmpty(S) || !isPair(pop(S), ch))
                {
                    balance = false;
                    goto end;
                }
        }
        i++;
    }

    // 在文件尾（这里是字符串）时，如果栈非空则报错
    if (!isEmpty(S))
        balance = false;

end:
    destroyStack(S);
    return balance;
}

static bool isPair(char open, char close)
{
    bool ok = false;

    if (open == '(' && close == ')')
        ok = true;
    else if (open == '[' && close == ']')
        ok = true;
    else if (open == '{' && close == '}')
        ok = true;

    return ok;
}