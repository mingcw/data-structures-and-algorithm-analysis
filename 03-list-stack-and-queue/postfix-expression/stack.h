#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100
#define EMPTY -1
#define FatalError(msg) \
{\
    puts(msg); \
    exit(EXIT_FAILURE); \
}

typedef int Position;
typedef int ElementType;

typedef struct StackRecord
{
    Position topOfStack; // 栈顶
    ElementType(*array)[SIZE]; // 栈空间，数组指针
} * Stack;


Stack createStack(void);
bool isEmpty(Stack S);
bool isFull(Stack S);
ElementType push(Stack S, ElementType X);
ElementType pop(Stack S);
void destroyStack(Stack S);

#endif // !STACK_H