// 二叉树接口的实现文件
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// 创建一颗单节点二叉树
// 并把 element 写入该节点
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

// 前序遍历，并对每个节点应用
// 且应用一次fun指向的函数
void preorderTraversal(Tree T, pfunc fun)
{
    if (T != NULL)
    {
        (*fun)(T->element);
        preorderTraversal(T->left, fun);
        preorderTraversal(T->right, fun);
    }
}

// 中序遍历，并对每个节点应用
// 且应用一次fun指向的函数
void inorderTraversal(Tree T, pfunc fun)
{
    if (T != NULL)
    {
        inorderTraversal(T->left, fun);
        (*fun)(T->element);
        inorderTraversal(T->right, fun);
    }
}

// 后序遍历，并对每个节点应用
// 且应用一次fun指向的函数
void postorderTraversal(Tree T, pfunc fun)
{
    if (T != NULL)
    {
        postorderTraversal(T->left, fun);
        postorderTraversal(T->right, fun);
        (*fun)(T->element);
    }
}

// 销毁树（递归）
void destroyTree(Tree T)
{
    if (T != NULL)
    {
        destroyTree(T->left);
        destroyTree(T->right);
        free(T);
    }
}