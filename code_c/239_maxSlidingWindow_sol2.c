/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }
    // 单调队列思路，从左到右递减；思路类同第一个保存第一第二个最大值思路
    int maxQueIdx[numsSize];
    int resSize = numsSize - k + 1;
    int *resArr = (int *)malloc(resSize * sizeof(int));
    if (resArr == NULL) { return NULL; }
    *returnSize = resSize;

    int i;
    int left = 0;
    int right = 0;
    for (i = 0; i < k; i++) {
        while (left < right && nums[i] >= nums[maxQueIdx[right - 1]]) {
            right--; // 出队列
        }
        maxQueIdx[right++] = i;
    }
    resSize = 0;
    resArr[resSize++] =  nums[maxQueIdx[left]];

    for (i = k; i < numsSize; i++) {
        // 若窗口加入的新元素比队尾元素大于等于，则队尾元素出队列 
        // 之所以等于也要出队列，是因为下标idx最新，不容易移除窗口
        while (left < right && nums[i] >= nums[maxQueIdx[right - 1]]) { // 当前队尾元素为right - 1,队尾指针在right
            right--; // 出队列
        }
        maxQueIdx[right++] = i;

        while (maxQueIdx[left] <= i - k) { // 最大值不在窗外
            left++; // 弹出队首元素，左移
        }
        resArr[resSize++] =  nums[maxQueIdx[left]];
    }

    return resArr;
}