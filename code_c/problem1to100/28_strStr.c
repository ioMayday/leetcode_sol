// 2020年9月14日 08:01:59

//尝试1
int strStr(char * haystack, char * needle){
    if (!*needle) return 0;
    int lens_hay = strlen(haystack);
    int lens_ned = strlen(needle);
    if (lens_hay == 0 || lens_hay < lens_ned) {
        return -1;
    }

    int idx = -1;
    char *p1;
    char *p2;
    char *p1_advance = &haystack[lens_ned - 1]; //子串长度
    for (p1 = haystack; *p1_advance; p1_advance++) {
        char *p1_old = p1;
        p2 = needle;
        while (*p1 == *p2 && *p2) { //当前for的p1起始位匹配
            p1++;
            p2++;
        }
        if (!*p2) { //while循环匹配完成，由*p2为0条件退出
            idx = p1_old - haystack;
            return idx;
        }
        p1 = p1_old + 1; //目标字串后移一位
    }

    return idx;
}

// 尝试2
int strStr(char * haystack, char * needle){
    if (!*needle) return 0;
    
    char *p1;
    char *p2;
    char *p1_advance;
    int idx = -1;
    for (p1_advance = haystack, p2 = &needle[1]; *p2; p2++) { //第一句已经判断过needle[0]非空
        p1_advance++;
        if (!*p1_advance) {
            return idx; //needle长度比haystack长，无匹配
        }
    } //p1_advance的地址停留在needle末尾的长度

    for (p1 = haystack; *p1_advance; p1_advance++) {
        char *p1_old = p1;
        p2 = needle;
        while (*p1 == *p2 && *p2) {
            p1++;
            p2++;
        }
        if (!*p2) {
            idx = p1_old - haystack;
            return idx;
        }
        p1 = p1_old + 1;
    }

    return idx; //查找完无匹配
}


//参考代码
char *strstr(const char *haystack, const char *needle) {
// if needle is empty return the full string
if (!*needle) return (char*) haystack;
const char *p1;
const char *p2;
const char *p1_advance = haystack;
for (p2 = &needle[1]; *p2; ++p2) {
p1_advance++; // advance p1_advance M-1 times
}
for (p1 = haystack; *p1_advance; p1_advance++) {
char *p1_old = (char*) p1;
p2 = needle;
while (*p1 && *p2 && *p1 == *p2) {
p1++;
p2++;
}
if (!*p2) return p1_old;
p1 = p1_old + 1;
}
return NULL;
}