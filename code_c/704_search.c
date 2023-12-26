int search(int* nums, int numsSize, int target){
    if (nums == NULL) return -1;
    int left = 0;
    int right = numsSize - 1; // 左闭右闭区间

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

    return -1; // 遍历完未找到

}