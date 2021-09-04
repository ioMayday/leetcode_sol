// 类似题：26,27,80,283
int removeElement(int* nums, int numsSize, int val)
{
    int i, start;
    
    // 双指针
    for (i = 0, start = 0; i < numsSize; i++) {
        if (val == nums[i]) { // i负责找val的值
            continue;
        }

        if (start < i) { // 一旦不重复且start下标小于i，则将后面非重复值赋值到前面重复的地方
            nums[start] = nums[i]; // 从而不用开辟新空间，若start==i，则不用重复赋值
        }
        start++; // 只要没有重复值，start就要下移一位
    }

    return start;
}