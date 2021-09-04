/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
    不用优先队列/堆等复杂结构，就用双指针思路
    核心：
        1、新申请一个数组，记录nums1[i]与nums2[]数组结合的起始位置
        2、每次找1个最小值，就在nums1中for循环匹配一下最小的，从steps[i]的起点开始
*/
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes)
{
    long long tmp = (long long)nums1Size * nums2Size;
    k = (k > tmp) ? tmp : k;
    int *steps = (int*)malloc(nums1Size * sizeof(int));
    if (steps == NULL) {
        return NULL;
    }
    memset(steps, 0, nums1Size * sizeof(int));

    // 申请返回内存
    int **returnArr = (int**)malloc(k * sizeof(int*) + 100); // 返回每行的列数
    if (returnArr == NULL) {
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(k * sizeof(int) + 100); // 返回每行的列数
    if (*returnColumnSizes == NULL) {
        return NULL;
    }
    // printf("k = %d\n", k);

    int n1MinIdx = 0;
    int i;
    for (i = 0; i < k; i++) {
        int min = INT_MAX; // min要放在每一轮查找前初始，以免成了上一轮的min
        for (int j = 0; j < nums1Size; j++) { // 找一次两两匹配的最小值
            if (steps[j] < nums2Size && nums1[j] + nums2[steps[j]] < min) {
                min = nums1[j] + nums2[steps[j]];
                n1MinIdx = j;
            }
        }
        // 最终得到最小值对应的nums1的idx，以及对应的nums2[]下标steps[idx]
        int *p = (int*)malloc(2 * sizeof(int));
        if (p == NULL) {
            return NULL;
        }
        // printf("n1MinIdx = %d\n", n1MinIdx);
        p[0] = nums1[n1MinIdx];
        p[1] = nums2[steps[n1MinIdx]];
        // printf("n1MinIdx = %d\n", n1MinIdx);
        steps[n1MinIdx] += 1; // n1MindIdx对应nums2下标值后移一位
        returnArr[i] = p;
        returnColumnSizes[0][i] = 2; // 每行的列数为2
        // printf("returnColumnSizes[0][%d] = %d\n", i, returnColumnSizes[0][i]);
    }
    *returnSize = k;
    return returnArr;
}

/*
    感谢评论中：cnwsssss提供的思路

    思路：
    和之前几个题目思想很像，用一个数组来记录num1中每个元素在nums2中走了多远就可以，每次循环都是nums1和nums2加起来最小的nums1往前走一步

    JS代码：
var kSmallestPairs = function(nums1, nums2, k) {
    if (k > nums1.length * nums2.length ) {
        k = nums1.length * nums2.length
    }
    if (nums1.length == 0 || nums2.length == 0) {
        return [];
    }
    let steps = new Array(nums1.length);
    for (let i = 0; i < steps.length; i++) {
        steps[i] = 0;
    }
    let results = [];
    for (let i = 0; i < k; i++) {
        let min = Number.MAX_VALUE;
        let minStepIndex = 0;
        for (let j = 0; j < nums1.length; j++) {
            if (steps[j] < nums2.length && nums2[steps[j]] + nums1[j] < min) {
                min = nums2[steps[j]] + nums1[j];
                minStepIndex = j;
            }
        }
        results.push([nums1[minStepIndex], nums2[steps[minStepIndex]]]);
        steps[minStepIndex]++;
    }
    
    return results;
};

*/