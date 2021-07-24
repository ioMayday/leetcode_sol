// 基于1288题和56题解法做改进

// ver2:优化下i,j双指针移位操作

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
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes)
{
    // 特殊条件处理
    if (firstList == NULL || secondList == NULL || firstListSize == 0 || secondListSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = (int*)malloc(sizeof(int));
        if (*returnColumnSizes == NULL) {
            *returnSize = 0;
        }
        **returnColumnSizes = 0;
        return NULL;
    }

    // 输入已经是排好序的
    // 申请动态空间
    int maxListSize = firstListSize + secondListSize;
    int **resArr = (int**)malloc(sizeof(int*) * maxListSize);
    if (resArr == NULL) {
        *returnSize = 0;
        return NULL; // 不处理
    }
 
    int num = 0; // 保存独立区间数
    int a1, a2, b1, b2, left, right;
    int i = 0;
    int j = 0;
    int col = *firstListColSize;
    int minListSize = firstListSize < secondListSize ? firstListSize : secondListSize;
    while (i < firstListSize && j < secondListSize) {
        a1 = firstList[i][0];
        a2 = firstList[i][1];
        b1 = secondList[j][0];
        b2 = secondList[j][1];

        // 判断是否有交集
        if (a1 <= b2 && b1 <= a2) { // 有交集
            left = a1 > b1 ? a1 : b1;
            right = a2 < b2 ? a2 : b2;
            // 保存交集结果
            resArr[num] = (int*)malloc(sizeof(int) * col);
            if (resArr[num] == NULL) {
                *returnSize = 0;
                return NULL; // 不处理                    
            }
            resArr[num][0] = left;
            resArr[num][1] = right;
            num++;
        }

        // 移位操作
        if (a2 > b2) {
            j += 1;
        } else {
            i += 1;
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * num);
    if (*returnColumnSizes == NULL) {
        *returnSize = 0;
        return NULL; // 不处理
    }
    for (i = 0; i < num; i++) {
        (*returnColumnSizes)[i] = col;
    }

    *returnSize = num;
    return resArr;

}

