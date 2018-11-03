// ����������Ľӿ�ͷ�ļ�

#ifndef TREE_H
#define TREE_H

#define FatalError(msg) \
{\
    puts(msg); \
    exit(1); \
}

typedef int ElementType;
// ����ʵ���ļ��ﶨ������ TreeNode
struct TreeNode;
typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

SearchTree makeEmpty(SearchTree T);
Position find(ElementType X, SearchTree T);
Position findMin(SearchTree T);
Position findMax(SearchTree T);
SearchTree insert(ElementType X, SearchTree T);
SearchTree delete(ElementType X, SearchTree T);
ElementType retrieve(Position P);

#endif // !TREE_H
