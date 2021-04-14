/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 自己的思路：
// 1、先用二分法找到相等值
// 2、再在二分法缩小的范围内，往左右扩找边界

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    // 动态分配返回数组
    int *returnArray = (int *)malloc(2 * sizeof(int)); // 返回数组
    if (returnArray == NULL || returnSize == NULL) return NULL;
    returnArray[0] = -1;
    returnArray[1] = -1;
	*returnSize = 2; // 返回数组的长度, [-1, -1]只有两个数

    // returnArray = &g_returnArray[0];

    if (nums == NULL) {
        return returnArray;
    }

    // 先二分找到相等的地方
    int left = 0;
    int right = numsSize - 1; // 左闭右闭区间
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            break;  // 找到一个相等值，则跳出
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    // 判断是否为找到相等值，跳出情况
    if (left <= right) { // 若是跳出
        // 再往两边扩找边界
        // 找左边界
        int tmp = mid - 1;
        while (tmp >= left && nums[tmp] == target) {
            tmp--;
        }
        returnArray[0] = ++tmp;  // ++必须放在前面，先自加再赋值
        // 找右边界
        tmp = mid + 1;
        while (tmp <= right && nums[tmp] == target) {
            tmp++;
        }
        returnArray[1] = --tmp;  // --必须放在前面
    } 

    return returnArray; // 遍历完
}