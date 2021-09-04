/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//// 本篇解法参考的labuladong的C++滑窗模板，并进行C代码转换
//// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-shu-zu-ti-mu/hua-dong-chuang-kou-ji-qiao-jin-jie
#define MAX_LEN 128 // 26个小写字母
#define max(a, b) ((a > b) ? (a) : (b))
int lengthOfLongestSubstring(char * s)
{
    if (s == NULL) return 0;

    int hashWindow[MAX_LEN] = {0};
    int start = 0;
    int end = 0;
    int lenS = strlen(s);
    int res = 0;

    // 记录最小覆盖子串的起始索引及长度
    while (end < lenS) {
        // c 是将移入窗口的字符
        char c = s[end];
        // 更新窗内数据
        hashWindow[c]++;
        // 右移窗口
        end++;

        // 左侧窗口收缩
        while (hashWindow[c] > 1) {   // 当前窗内存在重复元素，重复左移，直到移除那个重复元素的值后，跳出
            // d 是将移出窗口的字符
            char d = s[start];
            // 左移窗口
            start++;
            // 进行窗口内数据的一系列更新
            hashWindow[d]--; // 当前窗内含有的键值更新
        }
        // 收缩完得到当前不重复子串的长度，比较后更新
        res = max(res, end - start);
    }

    // 遍历完返回长度
    return res;
}