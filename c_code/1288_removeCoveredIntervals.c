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

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
{
    if (intervalsSize == 1) {
        return intervalsSize; // 仅一行数据不用合并
    }

    int num = 0;
    qsort(intervals, intervalsSize, sizeof(int*), CompareIntArray2);
    int i, j;
    int row = intervalsSize;
    int col = *intervalsColSize;
    int left = intervals[0][0];
    int right = intervals[0][1];
    for (i = 1; i < row; i++) {
        if (right < intervals[i][1]) {
            if (right >= intervals[i][0]) {
                right = intervals[i][1]; // combine
            } else { // can't combine
                left = intervals[i][0];
                right = intervals[i][1];
            }
        } else {
            num++; // 被合并的区间数
        }
    }

    return intervalsSize - num; // 剩余区间数 = 总区间数 - 被删除的区间数
}