// 链表的游标实现法，接口头文件

#ifndef CURSOR_H

#include <stdio.h>
#include <stdlib.h>

#define SPACE_SIZE 102 // 至少需要 N+2 个节点空间, 游标空间和链表各有 1 个头结点
#define FatalError(msg) \
{\
    puts(msg); \
    exit(EXIT_FAILURE); \
}

typedef int ElementType;
typedef int Position;
typedef Position PtrToNode;
typedef PtrToNode List;
typedef void(*PFunc)(Position);

typedef struct Node
{
    ElementType element;
    Position next;
} Node;

Node cursorSpace[SPACE_SIZE];

void initCursorSpace(void);
Position cursorAlloc(void);
Position cursorFree(Position P);
List createList(void);
Position insert(List L, ElementType X);
Position find(List L, ElementType X);
Position findPrev(List L, ElementType X);
void delete(List L, Position P);
void destroyList(List L);
void traversal(List L, PFunc printNode);

#endif // !CURSOR_H