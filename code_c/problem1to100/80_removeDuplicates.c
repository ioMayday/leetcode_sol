// 类似题：26,27,80,283
int removeDuplicates(int* nums, int numsSize)
{
    int i, start;

    if (numsSize <= 2) { // 长度不大于1，则直接返回
        return numsSize;
    }
    
    // 双指针
    int cnt = 1;
    for (i = 1, start = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) { // i负责找不重复的值
            cnt++; // 得到出现次数
            if (cnt > 2) { // 出现次数大于2，则start坐标不移位
                continue;
            }
        } else {
            cnt = 1; // 不等时
        }
        if (nums[i - 1] != nums[i] || cnt == 2) { // 不相等时 或连续cnt==2时可赋值
            if (start < i) { // 一旦不重复且start下标小于i，则将后面非重复值赋值到前面重复的地方
                // printf("start=%d, i=%d\n", start, i); // for debug
                nums[start] = nums[i]; // 从而不用开辟新空间，若start==i，则不用重复赋值
            }
        }
        // 注意start++一定要放在continue后，且不能和i++合并
        start++; // 只要没有重复值，start就要下移一位
    }

    return start;
}