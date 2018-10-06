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

// ����ַ��������������Ƿ�ȫ���պ�
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
            // �������ŷ���ѹ��ջ��
            case '(':
            case '[':
            case '{':
                push(S, ch);
                break;

            // �����պ����ţ�����ǡ���ջ������ջ�������Ŀ��ŷ��š����ɶԡ��򱨴�
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

    // ���ļ�β���������ַ�����ʱ�����ջ�ǿ��򱨴�
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