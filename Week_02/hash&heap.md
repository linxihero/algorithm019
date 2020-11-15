# 哈希表
也叫散列表
## 基本信息
成员：key/value/散列函数；

复杂度：插入/删除/查询均为O(1)，最坏情况下都是O(N)

## 哈希冲突：
会导致效率退化到O（n），需要选择合适的哈希函数；

解决哈希冲突常用方法：
1. 拉链法；
2. 寻址法

## 工业代码使用的hash

1. hash map：

    * key-value对
    * key不重复，value可重复
   

2. hash set
    * 不重复元素的集合
    * set的实现可有多种方法；





----------

# 堆

## 应用场景
可用来寻找一堆数据中的最大值或者最小值；
任务的优先级；

## 常见形式

* 大根堆；
* 小根堆；
* 二叉堆
    * （实现容易，但不是最优）
* 斐波拉契堆
    * （主要工业应用，多叉堆）
* 其他

## 二叉堆
### 性质
通过完全二叉树实现（非二叉搜索树）；
二叉大顶堆满足性质：

* 一颗完全数
    * 树中元素均在左下；
    * 可以用数组实现；如果第一个元素在索引为0 处：
        * 索引为i的左孩子索引：2*i+1
        * 索引为i的右孩子索引：2*i+2
        * 索引为i的父节的索引：floor((i-1)/2)
* 树中任意节点的值总是>=其子节点的值；
* 堆顶元素就是最大值；

### 常见操作

| 操作 | 时间复杂度 | 操作方法 |  |
| --- | --- | --- | --- |
| 插入 | O(logn) | 新元素插入堆尾；再依次从尾向上调整堆 |  |
| 删除 | O(logn) | 堆尾元素替换堆顶；再依次从根向下调整堆 |  |

### 各类语言二叉堆的实现

[https://shimo.im/docs/Lw86vJzOGOMpWZz2/read](https://shimo.im/docs/Lw86vJzOGOMpWZz2/read)

C语言实现数组二叉大顶堆
```

// =============== 数组二叉大顶堆的实现 ↓ =================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int *heap = NULL;
int heapSize;
int capacity;
int parent(int i) { return (i - 1) / 2; }
int kthChild(int i, int k) { return 2 * i + k; }
bool isEmpty() { return heapSize == 0; }
bool isFull() { return heapSize == capacity; }
void BinaryHeapCreate(int cap) {
    heapSize = 0;
    capacity = cap;
    heap = (int *)malloc(sizeof(int)*(capacity + 1));
    memset(heap, -1, capacity+1);
}
int maxChild(int i) {
    int leftChild = kthChild(i, 1);
    int rightChild = kthChild(i, 2);
    return heap[leftChild] > heap[rightChild] ? leftChild : rightChild;
}
void heapifyUp(int i) {
    int insertValue = heap[i];
    while (i > 0 && insertValue > heap[parent(i)]) {
        heap[i] = heap[parent(i)];
        i = parent(i);
    }
    heap[i] = insertValue;
}
void heapifyDown(int i) {
    int child;
    int temp = heap[i];
    while (kthChild(i, 1) < heapSize) {
        child = maxChild(i);
        if (temp >= heap[child]) {
            break;
        }
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = temp;
}
int insert(int x) {
    if (isFull()) { 
        printf("Heap is full, No space to insert new element\n");
        return -1;
    }
    heap[heapSize] = x;
    heapSize ++;
    heapifyUp(heapSize - 1);
    return true;
}
int erase(int x) {
    if (isEmpty()) { 
        printf("Heap is empty, No element to delete\n");
        return -1; 
    }
    int maxElement = heap[x];
    heap[x] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(x);
    return maxElement;
}
int findMax() {
    if (isEmpty()) { return -1; }
    return heap[0];
}
void printHeap() {
    printf("nHeap = ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
// int main() {
//     BinaryHeapCreate(7);
//     insert(3);
//     insert(2);
//     insert(3);
//     insert(1);
//     insert(2);
//     insert(4);
//     insert(5);
//     insert(5);
//     insert(6);
//     printHeap();
//     erase(5);
//     printHeap();
//     erase(2);
//     printHeap();
//     return 0;
// }
// =============== 数组二叉大顶堆的实现 ↑ =================


```

