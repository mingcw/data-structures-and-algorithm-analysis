# 二叉查找树

> 二叉树是一种每个节点最多有 2 个子节点的树。
> 树有 1 个根节点，根节点有 1 到多个子节点，每个子节点又可以有任意个子节点。也可以不存在根节点，也就是空树。

二叉树的一个重要应用就是它在查找领域的使用。

使二叉树成为二叉查找树的一个重要性质是：对于树中的每个节点，它的左子树的所有节点值均小于该节点值，右子树的所有节点值均大于该节点值。此时二叉树按照「左-根-右」的递归顺序呈现了一种「有序」的状态，即为二叉查找树，又叫二叉搜索树（Binary Search Tree）

## 约定

简单起见，本例中的查找树，各个节点均存储不重复的整数值。

## 关键算法

## 初始化

依照树的递归定义，二叉查找树的大多接口都是递归实现的。在本程序示例中，makeEmpty() 接口遵照树的递归定义初始化了一颗树。而也有人选择创建一颗单节点树作为初始化操作。

## 删除

对于很多数据结构而言，最困难的操作一般都是删除。

如果节点没有儿子，那么直接删除。

如果节点有 1 个儿子，那么调整父节点的子节点指针（绕过该节点）指向父节点的孙节点。然后删除该节点。

如果节点有 2 个儿子。情况就比较复杂，方案之一是用其右子树的最小节点值代替该节点的数据，并递归删除那个节点（右子树的最小节点）。

> 如果删除的次数不多，可以使用 **软删除** 的策略：当一个节点要被删除时，它仍留在树中，只是做了一个被删除的标记。这种做法特别在处理有重复关键字时很有用，此时记录出现频数的域可以减 1。