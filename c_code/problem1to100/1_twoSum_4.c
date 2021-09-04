/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 2021年4月15日 22:28:26
// 思路：
// 先拷贝副本，到结构体数组里，保留下标和值
// 对结构体数组排序
// 夹逼法求和，找到与target相等的下标
typedef struct SortedNums {
    int val;
    int idx;
} SortedNums, *pSortedNums;

int comp(const void *a, const void *b)
{
    return ((pSortedNums)a)->val - ((pSortedNums)b)->val; // 升序排列
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    if (nums == NULL || numsSize == 0) return NULL;

    int *resArray = (int *)malloc(2 * sizeof(int));
    if (resArray == NULL) return NULL;
    *returnSize = 2;
    resArray[0] = -1;
    resArray[1] = -1;

    pSortedNums qsortedNums = (pSortedNums)malloc(numsSize * sizeof(SortedNums));
    if (qsortedNums == NULL) return NULL;
    // 拷贝
    int i;
    for (i = 0; i < numsSize; i++) {
        qsortedNums[i].val = nums[i];
        qsortedNums[i].idx = i;
    }

    // 排序
    qsort(qsortedNums, numsSize, sizeof(SortedNums), comp);
    
    i = 0;
    int j = numsSize - 1; // 闭区间[i, j]
    while (i < j) { // 当i==j时都没找到，则没有
        if (qsortedNums[i].val + qsortedNums[j].val < target) {
            i++;  // 左边界往右移，增大结果
        } else if (qsortedNums[i].val + qsortedNums[j].val > target) {
            j--; // 右边界往左移，减小结果
        } else if (qsortedNums[i].val + qsortedNums[j].val == target) {
            resArray[0] = qsortedNums[i].idx;
            resArray[1] = qsortedNums[j].idx;
            break;
        }
    }

    return resArray;
}
