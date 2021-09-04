//// 上一个解法是参考的官方解答
//// 本篇解法参考的labuladong的C++滑窗模板，并进行C代码转换
//// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-shu-zu-ti-mu/hua-dong-chuang-kou-ji-qiao-jin-jie
#define MAX_LEN 128
char * minWindow(char * s, char * t)
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

    for (i = 0; t[i]; i++) {
        hashNeed[t[i]]++;
    }
    // lenT = i;  // 原表达长度
    for (i = 0; i < MAX_LEN; i++) {
        if (hashNeed[i] != 0) { lenT++; } // 改成表达键元素个数
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
        // while (valid == need.size()) { // 原代码表示的键个数， 如 aa, 则键只有1个，值为2
        while (valid == lenT) {           // 而lenT则为 aa的长度，为2
            // 在这里更新最小覆盖子串
            if (end - start < minLen) {
                minStart = start;
                minLen = end - start;
            }
            // d 是将移出窗口的字符
            char d = s[start];
            // 左移窗口
            start++;
            // 进行窗口内数据的一系列更新
            if (hashNeed[d]) {
                if (hashWindow[d] == hashNeed[d])
                    valid--;
                hashWindow[d]--;
            }
        }
    }
    // 返回最小覆盖子串
    if (minLen == INT_MAX) { return ""; }
    s[minStart + minLen] = '\0'; // 利用原字符串返回，省空间

    return &s[minStart];
}