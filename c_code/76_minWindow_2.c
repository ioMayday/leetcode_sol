#define MAX_LEN 128 // ascii码只有128个
char * minWindow(char * s, char * t)
{
    int hash[MAX_LEN] = {0}; // ascii码hash表映射
    int left = 0;
    int right = 0;
    int minStart = 0;
    int minLen = INT_MAX;
    int lenS = strlen(s);
    // int lenT = strlen(t);

    int i, lenT;
    for (i = 0; t[i]; i++) {
        hash[t[i]]++;
    }
    lenT = i;

    int notFitNum = lenT;
    // O(n)遍历，right挪动到末尾结束
    while (right < lenS) { // 区间是左闭右开
        // 先找符合条件窗，右移right
        if (hash[s[right]] > 0) {
            notFitNum--;
        }
        hash[s[right]]--;  // 右指针经过时，将不匹配的减至负数，将匹配的减到0
        right++;

        // 再找最优解，右移left
        while (notFitNum == 0) { // 当前范围内已满足
            if (right - left < minLen) { // 更新下当前长度
                minLen = right - left;
                minStart = left;
            }

            // 重点重点
            hash[s[left]]++;  // 左指针移动时，又把负数加回来
            if (hash[s[left]] > 0) { // 右移left，减小长度
                notFitNum++;
            }
            left++; // 找到后，新起点left++，滑动到下个窗
        }

    }
    if (minLen == INT_MAX) { return ""; }
    s[minStart + minLen] = '\0'; // 利用原字符串返回，省空间

    return &s[minStart];
}

// // Ref Code
//#define LEN 125
//
//char * minWindow(char * s, char * t){
//    int hash[LEN] = {0};    /* 定义哈希表 */
//    int start = 0, end = 0; /* 左右指针 */
//    int slen = strlen(s), tlen = strlen(t); /* 两串的长度 */
//    int minstart = 0, minlen = INT_MAX;    /* 最小匹配串起点与长度 */
//
//    for (int i = 0; t[i]; i++) {
//        hash[t[i]]++;   /* 再统计串t中各元素的哈希值 */
//    }
//
//    while (end < slen) { /* 右指针从串s头移动到串s尾 */
//        if (hash[s[end]]-- > 0) {   /* 串s中当前元素在串t中出现过 */  // 玄机重点，不是匹配的则减1；每个if判断后，不管真假都会自减
//            tlen--; /* tlen-- */
//        }
//        //hash[s[end]]--; /* 串s中当前元素的哈希值减1 */
//        end++;  /* 右指针向右移动 */
//
//        while (tlen == 0) { /* 出现匹配的子串 */
//            if (end - start < minlen) {    /* 更新最小匹配串的起点和长度 */
//                minstart = start;
//                minlen = end - start;
//            }
//            /* 串s当前start的哈希值加1：
//             * 若大于0，则表示左指针start移动后的字串不符合条件
//             * 若小于等于0，则表示左指针start移动后的字串还能符合条件
//             */
//            hash[s[start]]++;
//            if (hash[s[start]] > 0) {
//                tlen++;
//            }
//            start++;
//        }
//    }
//
//    if (minlen != INT_MAX) {   /* 找到了最小匹配字串 */
//        char* t = (char*)malloc(sizeof(char)*(minlen+1));
//        *t = '\0';
//        strncat(t, s+minstart, minlen);
//        return t;
//    }
//
//    return ""; /* 未找到最小匹配子串，返回""即可 */
//}
