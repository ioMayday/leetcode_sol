
// input :
// [], 0
// [1], 1
// [1], 0

// 本地调试ok
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    // 动态分配返回数组
    int *returnArray = (int *)malloc(2 * sizeof(int)); // 返回数组
    if (returnArray == NULL || returnSize == NULL) return NULL;
    returnArray[0] = -1;
    returnArray[1] = -1;
	*returnSize = 2; // 返回数组的长度, [-1, -1]只有两个数

    if (nums == NULL || numsSize == 0) { // [],0 用例时，nums并不为空指针，只是定义了，但未赋值；
        return returnArray;              // 用numsSize=0来操作返回
    }

    // 找左边界
    int left = 0;
    int right = numsSize - 1; // 左闭右闭区间
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    // 边界限制简化，返回左边界判是否超过numsSize,因为left是从0开始往上增的，不用判小于0
    if (left >= numsSize || nums[left] != target) { ; }
    else  returnArray[0] = left;

    // 找右边界
    left = 0;
    right = numsSize - 1; // 左闭右闭区间
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            left = mid + 1;  // 注意要包含该mid + 1，便于收缩左侧范围
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

     // 边界限制简化，返回右边界判是否小于0，因为right是从numsSize-1开始往下减的，不用判大于numsSize
    if (right < 0 || nums[right] != target) { ; }
    else returnArray[1] = right;

    return returnArray; // 遍历完
}

int main(void)
{
    int nums[] = {5,7,7,8,8,10};
    int returnSize;
    int *res = searchRange(NULL, 0, 0, &returnSize);
    printf("%d %d\n", res[0], res[1]);

    return 0;
}
