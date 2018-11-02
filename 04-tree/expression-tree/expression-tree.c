#include <stdio.h>
#include "stack.h"
#include "tree.h"

#define SIZE 20

Tree postfixToTree(char * postfix);
static bool isNumber(char ch);
static void printNode(NodeElement X);

int main(void)
{
    char * str = "123*+45*6+7*+";
    Tree T;

    T = postfixToTree(str);

    puts("ǰ�����-ǰ׺���ʽ: ");
    preorderTraversal(T, printNode);
    puts("\n");

    puts("�������-��׺���ʽ: ");
    inorderTraversal(T, printNode);
    puts("\n");

    puts("��������-��׺���ʽ: ");
    postorderTraversal(T, printNode);
    puts("\n");

    destroyTree(T);

    return 0;
}

// ���ú�׺���ʽ����һ�ű��ʽ��
Tree postfixToTree(char * postfix)
{
    Stack S;
    Tree T;

    S = createStack();

    while (*postfix != '\0')
    {
        if (isNumber(*postfix))
        {
            T = createTree(*postfix);
            push(S, T);
        }
        else // �����
        {
            T = createTree(*postfix);
            T->right = pop(S);
            T->left = pop(S);
            push(S, T);
        }
        postfix++;
    }

    T = pop(S);
    destroyStack(S);

    return T;
}

static bool isNumber(char ch)
{
    return ch >= '0' && ch <= '9';
}

static void printNode(NodeElement X)
{
    printf("%c", X);
}