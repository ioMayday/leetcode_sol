/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
思路：
1）先把数组变为有序数组
2）先正常当个不重复的数组完成全排列功能
3）调用第二个与之前相同的数就continue，直到不同
*/

int *g_vis;

// 套用backtrack模板
void backtrack(int *nums, int numsSize, int *returnSize, int **res, int *track, int idx)
{
    // 到达叶节点track加入returnColumSizes，记录的路径已经等于数组长度停止
    int i;
    if (idx == numsSize) {
        int *ans = (int *)malloc(sizeof(int) * numsSize);
        if (ans == NULL) {
            return;
        }
        memcpy(ans, track, sizeof(int) * numsSize);
        res[(*returnSize)++] = ans;
        return;
    }

    // 递归遍历
    for (i = 0; i < numsSize; i++) {
        // 确认当前值是否在track里
        // i > 0 && nums[i] == nums[i - 1] && !g_vis[i - 1] 保证重复数从左到右只有第一个没被填入的才能被放入，即重复数的放置，只有一种顺序，从左到右依次去取重复数来放，从而减少重复排列
        if (g_vis[i] || (i > 0 && nums[i] == nums[i - 1] && !g_vis[i - 1])) {
            continue;
        }
        // 上面这个去重判断条件是核心中的核心

        // 不在的话，加入track
        track[idx] = nums[i];
        g_vis[i] = 1;
        // 继续向后遍历
        backtrack(nums, numsSize, returnSize, res, track, idx + 1);
        // 节点返回后，取出track中的值
        g_vis[i] = 0;
    }

    return;
}

int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

// 套用func模板
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // 申请对应大小的二维数组并分配空间
    int maxRow = 1, i;
    for (i = numsSize; i > 0; i--) {
        maxRow *= i;
    }
    int **res = (int **)malloc((maxRow) * sizeof(int*));
    if (res == NULL) {
        return NULL;
    }

    // 申请vis标记和track数组
    int *p = (int*)malloc(numsSize * sizeof(int));
    if (p == NULL) {
        return NULL;
    }
    int *track = p;
    p = (int*)malloc(numsSize * sizeof(int));
    if (p == NULL) {
        return NULL;
    }
    g_vis = p;
    memset(g_vis, 0, numsSize * sizeof(int));

    // 先对数组排序
    qsort(nums, numsSize, sizeof(int), cmp);

    // 回溯穷举所有可能排列
    *returnSize = 0;
    int idx = 0;
    backtrack(nums, numsSize, returnSize, res, track, idx); // 从0行开始放结果

    // 所有可能的总数只有回溯完后才知道
    // 计算返回数组中每行的列数
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    if (returnColumnSizes == NULL) {
        return NULL;
    }
    for (i = 0; i < *returnSize; i++) {
        // (*returnColumnSizes)[i] = numsSize;
        // 等价于上条语句，returnColumnSizes[0]将二级指针解引用为一级指针，[i]解引用到对应的val所在地方完成赋值
        returnColumnSizes[0][i] = numsSize;
    }

    return res;
}