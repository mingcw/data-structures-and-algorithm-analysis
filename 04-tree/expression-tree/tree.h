// 二叉树接口的头文件
#ifndef TREE_H
#define TREE_H

#include <stdio.h>

#define FatalError(msg) \
{\
    puts(msg); \
    exit(EXIT_FAILURE); \
}

typedef char NodeElement;
struct Node
{
    NodeElement element;
    struct Node * left;
    struct Node * right;
};
typedef struct Node * PtrToNode;
typedef PtrToNode Tree;
typedef void(*pfunc)(NodeElement);

Tree createTree(NodeElement X);
NodeElement retrieve(Tree T);
void preorderTraversal(Tree T, pfunc fun);
void inorderTraversal(Tree T, pfunc fun);
void postorderTraversal(Tree T, pfunc fun);
void destroyTree(Tree T);
#endif // !TREE_H
