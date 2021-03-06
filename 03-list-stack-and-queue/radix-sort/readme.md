# 使用链表的一个实例：基数排序

基数排序是「多趟桶式排序，按位进行」

## 桶式排序

### 算法

有 N 个 整数，范围从 1 到 M（或 0 到 M - 1）。留置一个 Count[M] 数组并初始化为 0。于是 Count 有 M 个单元（桶），并都是空的。当 Ai 被读入时，Count[Ai] 增 1。当所有元素均被读入，扫描数组 Count，打印输出排好序的表。

> 运行时间：O(M + N)

### 缺点

当数组元素间隔太大，最大值 M 也很大时，桶式排序有很多空桶，基于此，提出了基数排序，是按位进行多趟的桶式排序。

## 基数排序

### 算法步骤

1. 确定趟数 n。等于最大值的位数。
2. 生成桶。
3. 入桶。先按最低位，扫描数组，每个数放入对应桶里。
4. 出桶。所有桶的数依次放回原数组。
5. 重复 3.4，按照次最低位进行。直到 n 趟为止。
6. 销毁桶。

> 运行时间：O(P(N + B))，P 是趟数，N 是元素数，B 是桶数
