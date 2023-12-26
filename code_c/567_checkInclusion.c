//// 本篇解法参考的labuladong的C++滑窗模板，并进行C代码转换
//// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-shu-zu-ti-mu/hua-dong-chuang-kou-ji-qiao-jin-jie

#define MAX_LEN 128
bool checkInclusion(char *t, char *s)
// int checkInclusion(char *t, char *s)
{
    int hashNeed[MAX_LEN] = {0};  // 在本题中没有负数情况
    int hashWindow[MAX_LEN] = {0};
    int start = 0;
    int end = 0;
    int minStart = 0;
    int minLen = INT_MAX;
    int lenS = strlen(s);
    int i, lenT = 0;
    int valid = 0;
    int keyNum = 0;

    for (i = 0; t[i]; i++) {
        hashNeed[t[i]]++;
    }
    lenT = i;  // 原表达长度
    for (i = 0; i < MAX_LEN; i++) {
        if (hashNeed[i] != 0) { keyNum++; } // 改成表达键元素个数
    }

    // 记录最小覆盖子串的起始索引及长度
    while (end < lenS) {
        // c 是将移入窗口的字符
        char c = s[end];
        // 右移窗口
        end++;
        // 进行窗口内数据的一系列更新
        if (hashNeed[c]) { // count函数是查找该值是否存在
            hashWindow[c]++;
            if (hashWindow[c] == hashNeed[c]) // 原代码
                valid++;
        }

        // 判断左侧窗口是否要收缩
        while (end - start >= lenT) {       // 当前窗长大于t的长度时，就要左移left，因为窗长是固定的lenT
            // 在这里更新最小覆盖子串
            if (valid == keyNum) { // 键的个数
                // return 1; // 只含有匹配的字符
                return true;
            }
            // d 是将移出窗口的字符
            char d = s[start];
            // 左移窗口
            start++;
            // 进行窗口内数据的一系列更新
            if (hashNeed[d]) {
                if (hashWindow[d] == hashNeed[d])
                    valid--; // 匹配数减1
                hashWindow[d]--; // 当前窗内含有的键值更新
            }
        }
    }

    // 遍历完未找到符合的字符串
    // return -1;
    return false;
}