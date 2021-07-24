/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 参考：1、labuladong 2、如下
// 作者：zhangdengyu
// 链接：https://leetcode-cn.com/problems/permutations/solution/46-quan-pai-lie-by-ac_fun-peev/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int isContain(int *nums, int len, int val)
{
    int flag = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (nums[i] == val) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int g_trackNum = 0; // 用于递归调用时临时入栈用
int g_rowPos = 0;
void backtrack(int *nums, int numsSize, int **returnColumnSizes, int *track)
{
    // 到达叶节点track加入returnColumSizes，记录的路径已经等于数组长度停止
    int i;
    if (g_trackNum == numsSize) {
        // printf("back: g_rowPos = %d\n", g_rowPos);
        for (i = 0; i < numsSize; i++) {
            // printf("back: g_rowPos = %d\n", g_rowPos);
            returnColumnSizes[g_rowPos][i] = track[i];
        }
        g_rowPos++;
        return;
    }

    // 递归遍历
    for (i = 0; i < numsSize; i++) {
        // 确认当前值是否在track里
        if (isContain(track, g_trackNum, nums[i])) {
            continue;
        }

        // 不在的话，加入track
        // printf("back: g_trackNum = %d\n", g_trackNum);
        track[g_trackNum++] = nums[i];
        
        // 继续向后遍历
        backtrack(nums, numsSize, returnColumnSizes, track);
        // 节点返回后，取出track中的值
        g_trackNum--;
    }

    return;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // 计算所有可能的总数n!
    int row = 1, i;
    for (i = numsSize; i > 0; i--) {
        row *= i;
    }
    *returnSize = row;

    // printf("row = %d\n", row);

    // 计算返回数组中每行的列数
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    if (returnColumnSizes == NULL) {
        return NULL;
    }
    for (int i = 0; i < row; i++) {
        // (*returnColumnSizes)[i] = numsSize;
        // 等价于上条语句，returnColumnSizes[0]将二级指针解引用为一级指针，[i]解引用到对应的val所在地方完成赋值
        returnColumnSizes[0][i] = numsSize;
    }

    // 申请对应大小的二维数组并分配空间
    int **res = (int **)malloc((row + 10) * sizeof(int*));
    if (res == NULL) {
        return NULL;
    }
    int *p;
    for (i = 0; i < row; i++) {
        p = (int*)malloc((numsSize + 10) * sizeof(int));
        if (p == NULL) {
            return NULL;
        }
        res[i] = p;
    }
    p = (int*)malloc(numsSize * sizeof(int));
    if (p == NULL) {
        return NULL;
    }
    int *track = p;

    // 回溯穷举所有可能排列
    g_trackNum = 0;
    g_rowPos = 0;
    backtrack(nums, numsSize, res, track); // 从0行开始放结果

    // 返回res
    return res;
}