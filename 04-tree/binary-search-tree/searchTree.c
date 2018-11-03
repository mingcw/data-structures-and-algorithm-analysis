// ����������Ľӿ�ʵ���ļ�

#include <stdio.h>
#include <stdlib.h>
#include "searchTree.h"

struct TreeNode
{
    ElementType element;
    SearchTree left;
    SearchTree right;
};

// ����� - �ݹ�
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


// ����Ԫ�� X ���ڵ�λ��
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

// ������Сֵ - �ݹ�
Position findMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->left == NULL)
        return T;
    else
        return findMin(T->left);
}

// �������ֵ - �ǵݹ�
Position findMax(SearchTree T)
{
    if (T == NULL)
        return NULL;
    while (T->right != NULL)
        T = T->right;

    return T;
}

// ����Ԫ�� X - �ݹ�
SearchTree insert(ElementType X, SearchTree T)
{
    if (T != NULL)
    {
        if (X < T->element)
            T->left = insert(X, T->left);
        else if (X > T->element)
            T->right = insert(X, T->right);
        // ���� X �Ѿ������ʲô������
    }
    else
    {
        // �����ڴ棬����һ���ǿյĽڵ㣬д��Ԫ�� X
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Failed to allocate memory");

        T->element = X;
        T->left = NULL;
        T->right = NULL;
    }

    return T;
}

// ɾ��Ԫ�� X - �ݹ�
SearchTree delete(ElementType X, SearchTree T)
{
    Position tmpCell;

    if (T == NULL)
    {
        return NULL;
    }
    else if (X < T->element) // ȥ������
    {
        T->left  = delete(X, T->left); // !!! ǧ��ǵã�ɾ��������Ԫ�غ󣬷��ص�������ָ�룬
                                       //     ������µ�������������ָ���ϣ��������Ͷϵ���
    }
    else if (X > T->element) // ȥ������
    {
        T->right = delete(X, T->right);// !!! ͬ��
    }
    else // �ҵ���Ҫɾ���Ľڵ�
    if (T->left && T->right) // �����ӽڵ�
    {
        tmpCell = findMin(T->right);
        T->element = tmpCell->element;
        T->right = delete(T->element, T->right);
    }
    else                     // һ����û���ӽڵ�
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

// ����λ�� P ����Ԫ��
ElementType retrieve(Position P)
{
    if (P == NULL)
        FatalError("Position is unvalid.");
    return P->element;
}