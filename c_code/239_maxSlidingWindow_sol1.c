// Prior Quneue，完全用数组形式实现的最大堆功能
typedef struct MaxPriorQue {
    int** heap;  // 二维数组 heap[i][0/1] 0是idx,1是val
    int size;    // 当前队列大小
    int capcity; // 队列最大容量
} MaxPriorQueStru, *pMaxPriorQueStru;

void init(pMaxPriorQueStru p, int size)
{
    p->size = 0;
    p->heap = (int**)malloc((size + 1) * sizeof(int*));
    // if (p->heap == NULL) { return NULL;}
    p->capcity = size + 1;

    int i;
    for (i = 0; i < p->capcity; i++) {
        p->heap[i] = (int *)malloc(2 * sizeof(int));
        // if (p->heap[i] == NULL) { return NULL; }
    }

    return;
}

int cmpValOrIdx(int *a, int *b)
{
    return a[1] == b[1] ? a[0] - b[0] : a[1] - b[1]; // 优先比较数值，再比较下标
}

// 完全用数组形式实现的最大堆功能
void push(pMaxPriorQueStru p, int idx, int val)
{
    // 已保证堆足够大，不用担心溢出
    p->size += 1;

    // 先放末端节点
    p->heap[p->size][0] = idx;
    p->heap[p->size][1] = val;

    // 通过与上层节点不断比较交换，找到合适位置
    int i0 = p->size >> 1;
    int i1 = p->size;
    while (i0 > 0 && cmpValOrIdx(p->heap[i0], p->heap[i1]) < 0) {
        int *tmp = p->heap[i0]; // 交换二级指针指向的一级指针地址
        p->heap[i0] = p->heap[i1];
        p->heap[i1] = tmp;
        i1 = i0; // 继续往上一层末端节点比较
        i0 >>= 1;
    }

    return;
}

void pop(pMaxPriorQueStru p)
{
    // 将顶端的值与末尾节点交换，再自减容量
    int *tmp = p->heap[1]; // 交换二级指针指向的一级指针地址
    p->heap[1] = p->heap[p->size];
    p->heap[p->size] = tmp;
    p->size--;

    // 调整堆，把末尾节点下沉到合适位置
    int i = 1; // 从顶端开始
    while (i <= p->size) {
        int l = i << 1; // 左孩子索引
        int r = l + 1; // 右孩子索引
        int max = i;
        if (l <= p->size && cmpValOrIdx(p->heap[max], p->heap[l]) < 0) {
            max = l;
        }
        if (r <= p->size && cmpValOrIdx(p->heap[max], p->heap[r]) < 0) {
            max = r;
        }
        if (max == i) { // 如果父节点就已是最大值，则调整完毕，顶端交换的值已找到合适位置
            break;
        }
        // 需要交换
        int *tmp = p->heap[i]; // 交换二级指针指向的一级指针地址
        p->heap[i] = p->heap[max];
        p->heap[max] = tmp;

        i = max; // 和max的指针交换后，当前max索引是被交换到顶端的底部值，待进一步下沉比较
    }
    // i下沉到最末端或者末尾节点已下沉到合适位置，结束调整

    return;
}

int* top(pMaxPriorQueStru p)
{
    return p->heap[1]; // 为方便下标引用，索引0空置不用
}

void SetFree(pMaxPriorQueStru p)
{
    int i;
    for (i = 0; i < p->capcity; i++) {
        free(p->heap[i]);
    }
    free(p->heap);
    free(p);
    return;
}

// 利用最大堆队列数据结构来完成
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }

    // 压入前k个数据
    pMaxPriorQueStru q = (pMaxPriorQueStru)malloc(sizeof(MaxPriorQueStru));
    if (q == NULL) { return NULL; }
    init(q, numsSize);

    int resSize = numsSize - k + 1;
    int *resArr = (int *)malloc(resSize * sizeof(int));
    if (resArr == NULL) { return NULL; }

    int end = 0;
    int i;
    for (i = 0; i < k; i++) {
        push(q, i, nums[i]);
    }
    int *heap = top(q);
    // resArr[*returnSize++] = heap[1]; // 作用是：resArr[*returnSize], 再returnSize++，加在地址上了，与预期不符
    resArr[end++] = heap[1];
    //printf("%d \n", *returnSize);
    //printf("%d ", heap[1]);

    // 从k往后移动
    for (i = k; i < numsSize; i++) {
        push(q, i, nums[i]);
        heap = top(q);
        while (heap[0] <= i - k) {
            pop(q);
            heap = top(q);
        }
        //resArr[*returnSize++] = heap[1];
        resArr[end++] = heap[1];
        // printf("%d \n", *returnSize);
        // printf("%d ", heap[1]);
    }
    //printf("%d \n", *returnSize);

    *returnSize = end;
    SetFree(q);

    return resArr;
}