// 
// "abcdxabcde"
// "abcdeabcdx" 
// output: true
#define MAX_LEN 128 // 26个小写字母
bool checkInclusion(char * s1, char * s2) 
{
    int hash[MAX_LEN] = {0}; // 输入只为小写字母
    int lenS2 = strlen(s2);
    int i;
    for (i = 0; s1[i]; i++) {
        hash[s1[i] - 'a']++;
    }
    int lenS1 = i;

    int left = 0;
    int right = 0;

    int notFitNum = lenS1;
    // O(n)遍历，right挪动到末尾结束
    while (right < lenS2) { // 区间是左闭右开
        // 先找符合条件窗，右移right
        if (hash[s2[right] - 'a'] > 0) {
            notFitNum--;
        }
        hash[s2[right] - 'a']--;  // 右指针经过时，将不匹配的减至负数，将匹配的减到0
        right++;

        // 再找最优解，右移left
        if (notFitNum == 0) { // 当前范围内已满足
            // 重点重点
            while (hash[s2[left] - 'a'] < 0) { //移动指针到第一个满足的字符
                hash[s2[left] - 'a']++;
                left++;
            }
            // 开始判断连续性
            // while (hash[s2[left] - 'a'] == 0 && left < right) { // 不要越界
            while (left < right && hash[s2[left] - 'a'] == 0) { // 数组下标先判范围再引用
                hash[s2[left] - 'a']++;
                left++;
                notFitNum++;
            }
            if (notFitNum == lenS1) {
                return true;
            }
            left = right;
        }

    }
    return false;
}