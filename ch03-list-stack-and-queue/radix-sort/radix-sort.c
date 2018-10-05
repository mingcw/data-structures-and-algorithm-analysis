#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define RADIX 10
#define BUCKETS_NUMBER RADIX
#define EMPTY -1
#define FatalError(msg) \
{\
    puts(msg); \
    exit(EXIT_FAILURE); \
}

struct Node
{
    int number;
    struct Node * next;
};

typedef struct Node Node;
typedef Node * PtrToNode;
typedef PtrToNode List;

void radixSort(int arr[], int size);
int getMaxDigits(int arr[], int size);
void push(List bucket, int number);
int popAll(List bucket, int arr[], int size, int start);

int main(void)
{
    int arr[SIZE] = { 64, 8, 216, 512, 27, 729, 0, 1, 343, 125 };

    radixSort(arr, SIZE);
    for (int i = 0; i < SIZE; i++)
        printf("%d,", arr[i]);

    return 0;
}

// 基数排序
void radixSort(int arr[], int size)
{
    List buckets[RADIX];
    int digits, count = 0, digit, base = 1;

    // 1. 获取趟数
    digits = getMaxDigits(arr, size);

    // 2. 初始化桶
    for (int i = 0; i < BUCKETS_NUMBER; i++)
    {
        buckets[i] = (PtrToNode)malloc(sizeof(Node));
        if (!buckets[i])
            FatalError("Failed to allocate memory.");

        buckets[i]->next = NULL;
    }

    // 5. 重复 3.4.
    while (count < digits)
    {
        // 3. 入桶
        for (int i = 0; i < SIZE; i++)
        {
            digit = arr[i] / base % RADIX;   // 取出每一位
            push(buckets[digit], arr[i]);
            arr[i] = EMPTY; // 元素离开数组
        }

        // 4. 出桶
        for (int i = 0, start = 0; i < BUCKETS_NUMBER; i++)
        {
            start = popAll(buckets[i], arr, SIZE, start);
        }

        base *= RADIX;
        count++;
    }

    // 6. 销毁桶
    for (int i = 0; i < BUCKETS_NUMBER; i++)
        free(buckets[i]);
}

// 获取最大数的位数
int getMaxDigits(int arr[], int size)
{
    int base = 1, digits = 0, max = arr[0];

    // 获取 max
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    // 获取 max 的位数
    while (max > 0)
    {
        digits++;
        max /= RADIX;
    }

    return digits;
}

// 数字入桶
void push(List bucket, int number)
{
    PtrToNode pCell, pNode;

    pCell = (PtrToNode)malloc(sizeof(Node)); // 分配一个存储单元
    if (!pCell)
        FatalError("Failed to allocate memory.");

    pCell->number = number;
    pCell->next = NULL;

    pNode = bucket;      // 头结点不存储数据
    while (pNode->next)  // 找尾节点
        pNode = pNode->next;
    pNode->next = pCell; // 尾插法
}

// 清空桶，数据依次放回原数组，起始
// 偏移为 start， 返回放入数组的最
// 后一个元素的下一偏移
int popAll(List bucket, int arr[], int size, int start)
{
    PtrToNode pNode, tmp;

    pNode = bucket->next; // 从头结点的后继开始
    while (pNode)
    {
        if (start >= size)
            FatalError("Out of limit of array.");

        arr[start++] = pNode->number; // 放回数组
        tmp = pNode;
        pNode = pNode->next;
        free(tmp);
    }
    bucket->next = NULL;
    return start;
}