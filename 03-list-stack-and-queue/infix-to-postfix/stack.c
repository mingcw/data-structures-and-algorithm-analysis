#include "stack.h"

Stack createStack(void)
{
    Stack S;

    S = (Stack)malloc(sizeof(struct StackRecord));
    if (S == NULL)
        FatalError("Failed to create stack.");

    S->array = (ElementType(*)[SIZE])malloc(sizeof(ElementType)* SIZE);
    S->topOfStack = EMPTY;
    return S;
}

bool isEmpty(Stack S)
{
    return S->topOfStack == EMPTY;
}

bool isFull(Stack S)
{
    return S->topOfStack == SIZE - 1; // topOfStack 从 0 开始
}

ElementType push(Stack S, ElementType X)
{
    if (isFull(S))
        FatalError("Stack is full.");

    (*S->array)[++S->topOfStack] = X;
    return X;
}

ElementType pop(Stack S)
{
    if (isEmpty(S))
        FatalError("Stack is empty.");

    return (*S->array)[S->topOfStack--];
}

ElementType top(Stack S)
{
    if (isEmpty(S))
        FatalError("Stack is empty.");

    return (*S->array)[S->topOfStack];
}

void destroyStack(Stack S)
{
    free(S->array);
    free(S);
}
