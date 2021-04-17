// 本题不熟，需要多练习
// 知道思路后，1h才写好debug完通过
int GetMaxVal(int* weights, int weightsSize, int* sum)
{
    int maxVal = 0;
    int resSum = 0;
    int i;
    for (i = 0; i < weightsSize; i++) {
        if (weights[i] > maxVal) maxVal = weights[i];
        resSum += weights[i];
    }

    *sum = resSum;
    return maxVal;
}

int CanFinish(int* weights, int weightsSize, int D, int load)
{
    int i = 0, day;
    
    for (day = 1; day <= D; day++) { //day必须是按天加的，适合for
        int curLoad = load;
        while ((curLoad -= weights[i]) >= 0) { //注意是大于等于，而非大于
            i++;
            if (i == weightsSize) return 1; // <=D天内运完
        }
    }

    return 0; // 在D天内没运完
}

// 二分查找的应用
int shipWithinDays(int* weights, int weightsSize, int D){
    int right = -1;  // 最大运载能力为所有包裹重量和，一次搞定
    int left = GetMaxVal(weights, weightsSize, &right);  // 最大的包裹重量作为最小的船运载能力
    int sum = right;
    while (left <= right) { // 搜索左边界，找最低运载能力
        int mid = left + (right - left) / 2;
        if (CanFinish(weights, weightsSize, D, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1; // 若mid不能满足，mid以下的更不能
        }
    }
    // 不用检验边界，本来就是在已有边界下往里缩
    // 不过以防保险，还是校验下
    if (left > sum) return -1;  // 理论上照题目的输入是跑不到这句的

    return left;
}