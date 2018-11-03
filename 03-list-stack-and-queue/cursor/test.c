// 链表的游标实现法，测试文件

#include <stdio.h>
#include "cursor.h"

#define SIZE (SPACE_SIZE - 2) // 链表允许的最大节点数

static void printNode(Position P);

int main(void)
{
    List L;

    initCursorSpace();
    L = createList();

    for (int i = 0; i < SIZE; i++)
        insert(L, i + 1);
    puts("Initial List:");
    traversal(L, printNode);
    puts("\n");

    for (int i = 0; i <= SIZE; i += 2)
        delete(L, find(L, i));
    puts("Now list:");
    traversal(L, printNode);
    puts("\n");

    destroyList(L);
    return 0;
}

static void printNode(Position P)
{
    printf("%d, ", cursorSpace[P].element);
}