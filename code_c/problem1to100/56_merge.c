// 基于1288题解法做改进

/*
1、先排序，起始从小到大，相同时终点从大到小
2、分情况进行合并，双指针left/right来移动并判断新区间是否在里面，并合并
*/

int CompareIntArray2(const void *a, const void *b)
{
    int ret = *(*(int **)a) - *(*(int **)b);
    if (ret == 0) { // 起点相同时按终点来比较
        ret = *(*(int **)b + 1) - *(*(int **)a + 1);
    }
    return ret;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    if (intervalsSize == 1) {
        *returnSize = 1;
        *returnColumnSizes = (int*)malloc(sizeof(int));
        if (*returnColumnSizes == NULL) {
            *returnSize = 0;
        }
        **returnColumnSizes = *intervalsColSize;
        return intervals; // 仅一行数据不用合并
    }

    qsort(intervals, intervalsSize, sizeof(int*), CompareIntArray2);
    int i, j;
    int row = intervalsSize;
    int col = *intervalsColSize;

    // 申请动态空间
    int **resArr = (int**)malloc(sizeof(int*) * intervalsSize);
    if (resArr == NULL) {
        *returnSize = 0;
        return intervals; // 不处理
    }
 
    int num = 0; // 保存独立区间数
    int left = intervals[0][0];
    int right = intervals[0][1];
    for (i = 1; i < row; i++) {
        if (right < intervals[i][1]) {
            if (right >= intervals[i][0]) {
                right = intervals[i][1]; // combine
            } else { // can't combine
                // 保存当前独立区间
                resArr[num] = (int*)malloc(sizeof(int) * col);
                if (resArr[num] == NULL) {
                    *returnSize = 0;
                    return intervals; // 不处理                    
                }
                resArr[num][0] = left;
                resArr[num][1] = right;
                num++;

                // 移动到下一区间
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
    }
    // 保存最后一个独立区间数
    resArr[num] = (int*)malloc(sizeof(int) * col);
    if (resArr[num] == NULL) {
        *returnSize = 0;
        return intervals; // 不处理                    
    }
    resArr[num][0] = left;
    resArr[num][1] = right;
    num++;

    *returnColumnSizes = (int*)malloc(sizeof(int) * num);
    if (*returnColumnSizes == NULL) {
        *returnSize = 0;
        return intervals; // 不处理
    }
    for (i = 0; i < num; i++) {
        (*returnColumnSizes)[i] = col;
    }

    *returnSize = num;
    return resArr;

}