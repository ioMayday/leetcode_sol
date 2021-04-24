typedef struct PaliInfo {
    int maxLen;
    int start;
    int end;
} PaliInfoStru, *HandlePaliInfoStru;

// 以当前位置为中心，获取最大回文字符串，并比较更新
void GetPalindrome(char *s, int len, int l, int r, HandlePaliInfoStru paliInfoMax)
{
    while (l >= 0 && r < len && s[l] == s[r]) {
        l--;
        r++;
    }
    int start = l + 1;
    int end = r - 1;
    int paliLen = end - start + 1;

    // update
    if (paliInfoMax->maxLen < paliLen) {
        paliInfoMax->maxLen = paliLen;
        paliInfoMax->start = start;
        paliInfoMax->end = end;
    }

    return;
}

char* longestPalindrome(char *s)
{
    if (s == NULL) { return NULL; }

    int len = strlen(s);
    PaliInfoStru paliInfoMax = {INT_MIN, -1, -1};
    int i;
    for (i = 0; i < len; i++) {
        GetPalindrome(s, len, i, i, &paliInfoMax);        // 奇数中心
        GetPalindrome(s, len, i, i + 1, &paliInfoMax);    // 偶数中心
    }

    // 输出最大回文子串
    char *outStr = (char *)malloc(paliInfoMax.maxLen + 1); // 多一个给/0
    if (outStr == NULL) { return NULL; }
    strncpy(outStr, s + paliInfoMax.start, paliInfoMax.maxLen);
    outStr[paliInfoMax.maxLen] = '\0';

    return outStr;
}