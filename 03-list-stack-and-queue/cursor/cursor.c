// 链表的游标实现法，实现文件

#include "cursor.h"

void initCursorSpace(void)
{
    for (int i = 0; i < SPACE_SIZE - 1; i++)
        cursorSpace[i].next = i + 1;
    cursorSpace[SPACE_SIZE - 1].next = 0;
}

Position cursorAlloc(void)
{
    Position first = cursorSpace[0].next; // 分配头结点的后继
    cursorSpace[0].next = cursorSpace[first].next;

    return first;
}

Position cursorFree(Position P)
{
    cursorSpace[P].next = cursorSpace[0].next; // 回收节点 1
    cursorSpace[0].next = P;

    return P;
}


List createList(void)
{
    Position head;

    head = cursorAlloc();
    cursorSpace[head].next = 0;

    return head;
}

// 在 L 中 插入 X（尾插法）
Position insert(List L, ElementType X)
{
    Position P, tmp;

    P = cursorAlloc();
    if (P == 0)
        FatalError("Out of space.");

    cursorSpace[P].element = X;
    cursorSpace[P].next = 0;

    tmp = L;
    while (cursorSpace[tmp].next != 0) // 找尾节点
        tmp = cursorSpace[tmp].next;
    cursorSpace[tmp].next = P;       // 追加新节点

    return P;
}

// 返回 X 在 L 中第一次出现的位置,
// 没找到则返回 0
Position find(List L, ElementType X)
{
    Position P;

    P = cursorSpace[L].next;
    while (P && cursorSpace[P].element != X)
        P = cursorSpace[P].next;
    return P;
}

// 返回 X 在 L 中首次出现时前驱元的
// 位置, 没找到时返回 0
Position findPrev(List L, ElementType X)
{
    Position P;

    P = cursorSpace[L].next;
    while (P && cursorSpace[cursorSpace[P].next].element != X)
        P = cursorSpace[P].next;
    return P;
}

// 删除 L 中 P 位置处的节点
void delete(List L, Position P)
{
    Position prev;

    prev = findPrev(L, cursorSpace[P].element);
    cursorSpace[prev].next = cursorSpace[P].next;
    cursorFree(P);
}

// 销毁链表
void destroyList(List L)
{
    cursorSpace[L].next = 0;
}

// 对链表的每一个节点，应用一次函数 pfunc
void traversal(List L, PFunc pfunc)
{
    Position P = cursorSpace[L].next;

    while (P)
    {
        (*pfunc)(P);
        P = cursorSpace[P].next;
    }
}