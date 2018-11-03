// ����������Ľӿڲ��ԣ��������ļ�

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

    // ��ʼ��һ�ſ���
    T = makeEmpty(NULL);

    // �� 7 Ϊ������SIZE = 20 Ϊ��Χ���� 0 ��ʼ
    // ������ 0, 7, 14, 1, 8, ... , 13 �� 20 ��
    // ���ظ����֣����β��뵽��������� T �
    for (i = 0; i < SIZE; i++, j = (j + 7) % SIZE)
        T = insert(j, T);

    // ȷ������������ɹ�
    for (i = 0; i < SIZE; i++)
        if ((P = find(i, T)) == NULL || retrieve(P) != i)
            printf("Error at %d\n", i);
    
    // ɾ��ż���ڵ�
    for (i = 0; i < SIZE; i += 2)
        T = delete(i, T);

    // ȷ�������ڵ�
    for (i = 1; i < SIZE; i += 2)
        if ((P = find(i, T)) == NULL || retrieve(P) != i)
            printf("Error at %d\n", i);

    // ȷ��ż���ڵ�ɾ���ɹ�
    for (i = 0; i < SIZE; i += 2)
        if ((P = find(i, T)) != NULL)
            printf("Error at %d\n", i);

    // ��ӡ������ֵ min, max
    printf("Min is %d, Max is %d\n", retrieve(findMin(T)),
        retrieve(findMax(T)));

    return 0;
}