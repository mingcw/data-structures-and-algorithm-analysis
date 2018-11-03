// 二叉查找树的接口实现文件

#include <stdio.h>
#include <stdlib.h>
#include "searchTree.h"

struct TreeNode
{
    ElementType element;
    SearchTree left;
    SearchTree right;
};

// 清空树
SearchTree makeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
    return T;
}


// 查找元素 X 所在的位置
Position find(ElementType X, SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (X < T->element)
        return find(X, T->left);
    else if (X > T->element)
        return find(X, T->right);
    else
        return T;
}

// 查找最小值
Position findMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->left == NULL)
        return T;
    else
        return findMin(T->left);
}

// 查找最大值 - 非递归
Position findMax(SearchTree T)
{
    if (T == NULL)
        return NULL;
    while (T->right != NULL)
        T = T->right;

    return T;
}

// 插入元素
SearchTree insert(ElementType X, SearchTree T)
{
    if (T != NULL)
    {
        if (X < T->element)
            T->left = insert(X, T->left);
        else if (X > T->element)
            T->right = insert(X, T->right);
        // 否则 X 已经在树里，什么都不做
    }
    else
    {
        // 分配内存，创建一个非空的节点，写入元素 X
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Failed to allocate memory");

        T->element = X;
        T->left = NULL;
        T->right = NULL;
    }

    return T;
}

// 删除元素
SearchTree delete(ElementType X, SearchTree T)
{
    Position tmpCell;

    if (T == NULL)
    {
        return NULL;
    }
    else if (X < T->element) // 去左子树
    {
        T->left  = delete(X, T->left); // !!! 千万记得：删除了子树元素后，返回的新子树指针，
                                       //     必须更新到树根的左子树指针上，否则树就断掉了
    }
    else if (X > T->element) // 去右子树
    {
        T->right = delete(X, T->right);// !!! 同上
    }
    else // 找到了要删除的节点
    if (T->left && T->right) // 两个子节点
    {
        tmpCell = findMin(T->right);
        T->element = tmpCell->element;
        T->right = delete(T->element, T->right);
    }
    else                     // 一个或没有子节点
    {
        tmpCell = T;
        if (T->left == NULL)
            T = T->right;
        else if (T->right == NULL)
            T = T->left;
        free(tmpCell);
    }

    return T;
}

// 检索位置 P 处的元素
ElementType retrieve(Position P)
{
    if (P == NULL)
        FatalError("Position is unvalid.");
    return P->element;
}
