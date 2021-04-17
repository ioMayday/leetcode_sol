int SplitStr(char *version, const char *split, int *verNum, int len)
{
    char *p = strtok(version, split);
    while (p) {
        verNum[len++] = atoi(p);
        p = strtok(NULL, split);
    }
    return len;
}

int compareVersion(char * version1, char * version2)
{
    // 切割ver1和ver2，放到数组，并记录长度
    int ver1[500] = {0};
    int ver2[500] = {0};
    int lenVer1 = 0, lenVer2 = 0;
    char *p;
    const *split = ".";
    lenVer1 = SplitStr(version1, split, ver1, lenVer1);
    lenVer2 = SplitStr(version2, split, ver2, lenVer2);
    
    // 比较数组
    int minLen = lenVer1 < lenVer2 ? lenVer1 : lenVer2;
    int i;
    for (i = 0; i < minLen; i++) {
        if (ver1[i] > ver2[i]) {
            return 1;
        } else if (ver1[i] < ver2[i]) {
            return -1;
        }
    }
    // 解决下类用例
    // "1.0"
    // "1.0.0"
    // 判断长版本号，后续是否都为0
    if (minLen == lenVer1) { // 长的是lenVer2
        for (i = lenVer1; i < lenVer2; i++) {
            if (ver2[i] != 0) {
                break;
            }
        }
        if (i == lenVer2) { // 长版本号后续全为0
            return 0;
        }
    } else {
        for (i = lenVer2; i < lenVer1; i++) {
            if (ver1[i] != 0) {
                break;
            }
        }
        if (i == lenVer1) { // 长版本号后续全为0
            return 0;
        }
    }

    // 最小长度数组退出且前面break
    // 即每个号都相同且长版本号后续不全为0
    // 比较段数
    if (lenVer1 > lenVer2) {
        return 1;
    } else if (lenVer1 < lenVer2) {
        return -1;
    }
    // lenVer1 == lenVer2)
    return 0;  // 长度相等
}