// 暴力解法会runtime error: signed integer overflow，二分法不会，极限用例如下：
// [332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184]
// 823855818
// 此题在二分法时，判左右边界时容易出问题，要反复练习，加深体会

int GetMaxVal(int* piles, int pilesSize)
{
    int maxVal, i;
    maxVal = INT_MIN;
    for (i = 0; i < pilesSize; i++) {
        if (piles[i] > maxVal) {
            maxVal = piles[i];
        }
    }

    return maxVal;
}

int timeOf(int s, int speed)
{
    return s / speed + ((s % speed > 0) ? 1 : 0);
}

int CanFinish(int* piles, int pilesSize, int h, int speed)
{
    int isFlag = 0;
    int i, timeSum = 0;
    for (i = 0; i < pilesSize; i++) {
        timeSum += timeOf(piles[i], speed);
    }
    if (timeSum <= h) isFlag = 1;

    return isFlag;
}

int minEatingSpeed(int* piles, int pilesSize, int h){
     // 二分查找解法
     if (piles == NULL || pilesSize == 0) return -1;

     int minSpeed = 1;
     int right = GetMaxVal(piles, pilesSize);
     
     while (minSpeed <= right) { // 找相等时的左边界，即最小值
         int mid = minSpeed + (right - minSpeed) / 2;
         if (CanFinish(piles, pilesSize, h, mid)) { // 如果相等
             right = mid - 1; // 右侧边界左移
        } else {  // 如果不满足，则不断缩小右侧范围
             minSpeed = mid + 1;  // 左侧边界右移，mid越大，表示速度越快，越容易满足
         }
     }
     
     return minSpeed;
}
