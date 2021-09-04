int lengthOfLongestSubstring(char * s){
    int len_s = strlen(s);
    if (len_s == 0 || len_s == 1) {
        return len_s;
    }

    int curIdx = 0;
    int maxLen = 1;
    int i,j;
    for (i = 1; i < len_s; i++) { //从前往后增长子串
        for (j = i- 1; j >= curIdx; --j) { //每后移一个s[i]，均以当前子串起点间判断是否出现过该字符
            if (s[i] == s[j]) { //判断新出现的s[i]是否跟前面的一样
                curIdx = j + 1; //新子串只能往后移
                break; //跳出内部for循环
            } 
            
            if (maxLen < i - j + 1) {
                maxLen = i - j + 1; //当前的子串长度更长
            }
        }
    }
    return maxLen;
}