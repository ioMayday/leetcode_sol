int removeDuplicates(int* nums, int numsSize)
{
    int i, start;

    if (numsSize <= 1) { // 长度不大于1，则直接返回
        return numsSize;
    }
    
    // 双指针
    for (i = 1, start = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) { // i负责找不重复的值
            continue;
        }

        if (start < i) { // 一旦不重复且start下标小于i，则将后面非重复值赋值到前面重复的地方
            nums[start] = nums[i]; // 从而不用开辟新空间，若start==i，则不用重复赋值
        }
        start++; // 只要没有重复值，start就要下移一位
    }

    return start;
}