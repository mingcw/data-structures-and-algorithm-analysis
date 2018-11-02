// �������ӿڵ�ʵ���ļ�
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// ����һ�ŵ��ڵ������
// ���� element д��ýڵ�
Tree createTree(NodeElement X)
{
    Tree T;

    T = (Tree)malloc(sizeof(struct Node));
    if (T == NULL)
        FatalError("Failed to create a tree.");

    T->element = X;
    T->left  = NULL;
    T->right = NULL;

    return T;
}

NodeElement retrive(Tree T)
{
    return T->element;
}

// ǰ�����������ÿ���ڵ�Ӧ��
// ��Ӧ��һ��funָ��ĺ���
void preorderTraversal(Tree T, pfunc fun)
{
    if (T != NULL)
    {
        (*fun)(T->element);
        preorderTraversal(T->left, fun);
        preorderTraversal(T->right, fun);
    }
}

// �������������ÿ���ڵ�Ӧ��
// ��Ӧ��һ��funָ��ĺ���
void inorderTraversal(Tree T, pfunc fun)
{
    if (T != NULL)
    {
        inorderTraversal(T->left, fun);
        (*fun)(T->element);
        inorderTraversal(T->right, fun);
    }
}

// �������������ÿ���ڵ�Ӧ��
// ��Ӧ��һ��funָ��ĺ���
void postorderTraversal(Tree T, pfunc fun)
{
    if (T != NULL)
    {
        postorderTraversal(T->left, fun);
        postorderTraversal(T->right, fun);
        (*fun)(T->element);
    }
}

// ���������ݹ飩
void destroyTree(Tree T)
{
    if (T != NULL)
    {
        destroyTree(T->left);
        destroyTree(T->right);
        free(T);
    }
}