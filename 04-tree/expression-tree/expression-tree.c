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

    puts("前序遍历-前缀表达式: ");
    preorderTraversal(T, printNode);
    puts("\n");

    puts("中序遍历-中缀表达式: ");
    inorderTraversal(T, printNode);
    puts("\n");

    puts("后续遍历-后缀表达式: ");
    postorderTraversal(T, printNode);
    puts("\n");

    destroyTree(T);

    return 0;
}

// 利用后缀表达式构造一颗表达式树
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
        else // 运算符
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