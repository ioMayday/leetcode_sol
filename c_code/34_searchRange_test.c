// int g_returnSize[2] = {0};
// input :
// [], 0
// [1], 1
// [1], 0

// 本地调试能通过，但leetcode对测试用例 [],0 报错堆栈溢出
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    // 动态分配返回数组
    int *returnArray = (int *)malloc(2 * sizeof(int)); // 返回数组
    if (returnArray == NULL || returnSize == NULL) return NULL;
    returnArray[0] = -1;
    returnArray[1] = -1;
	*returnSize = 2; // 返回数组的长度, [-1, -1]只有两个数

    // returnArray = &g_returnArray[0];

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
    // linux里&&不会区分nums[left]谁先谁后，这里left为1时依然要nums[left]出现地址越界
    // if (left < numsSize - 1 && nums[left] == target) returnArray[0] = left;
    // 修改后
    if (left < numsSize) {
        if (nums[left] == target)
            returnArray[0] = left;
    }

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
    // if (right < numsSize && nums[right] == target) returnArray[1] = right; //注意边界
    if (right < numsSize - 1) {
        if (nums[right] == target)
            returnArray[1] = right;
    }

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
