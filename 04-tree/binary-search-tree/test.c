// 二叉查找树的接口测试（驱动）文件

#include <stdio.h>
#include "searchTree.h"

#ifndef SIZE
#define SIZE 20
#endif // !SIZE


int main(void)
{
    SearchTree T;
    Position P;
    int i;
    int j = 0;

    // 初始化一颗空树
    T = makeEmpty(NULL);

    // 以 7 为步长，SIZE = 20 为范围，从 0 开始
    // 生成数 0, 7, 14, 1, 8, ... , 13 共 20 个
    // 不重复数字，依次插入到二叉查找树 T 里。
    for (i = 0; i < SIZE; i++, j = (j + 7) % SIZE)
        T = insert(j, T);

    // 确认所有数插入成功
    for (i = 0; i < SIZE; i++)
        if ((P = find(i, T)) == NULL || retrieve(P) != i)
            printf("Error at %d\n", i);
    
    // 删除偶数节点
    for (i = 0; i < SIZE; i += 2)
        T = delete(i, T);

    // 确认奇数节点
    for (i = 1; i < SIZE; i += 2)
        if ((P = find(i, T)) == NULL || retrieve(P) != i)
            printf("Error at %d\n", i);

    // 确认偶数节点删除成功
    for (i = 0; i < SIZE; i += 2)
        if ((P = find(i, T)) != NULL)
            printf("Error at %d\n", i);

    // 打印树的最值 min, max
    printf("Min is %d, Max is %d\n", retrieve(findMin(T)),
        retrieve(findMax(T)));

    return 0;
}