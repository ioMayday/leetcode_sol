// 此题思路清楚，代码容易出错，特别是进位要多练
char *multiply(char *num1, char *num2)
{
    if (num1 == NULL || num2 == NULL) { return NULL; }

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int* resNum = (int*)malloc((len1 + len2) * sizeof(int));
    if (resNum == NULL) { return NULL; }
    memset(resNum, 0, (len1 + len2) * sizeof(int));

    int i;
    int j;
    for (i = len1 - 1; i >= 0; i--) {
        int tmpNum = (int)(num1[i] - '0');
        for (j = len2 - 1; j >= 0; j--) {
            int res = tmpNum * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;

            // 叠加到res
            int sum = res + resNum[p2];
            resNum[p1] += sum / 10; // 注意高位是+=
            resNum[p2] = sum % 10;  // sum算入了p2位置的值
        }
    }

    // 结果转化成字符串
    i = 0;
    while (i < len1 + len2 && resNum[i] == 0) {
        i++;
    }
    if (i == len1 + len2) { return "0"; } // 针对 “0” “0”，结果全零

    // 转化成字符串
    char *resChar = (char*)malloc((len1 + len2 - i + 1) * sizeof(char)); // +1是给末尾结束符\0
    if (resChar == NULL) { return NULL; }
    j = 0;
    for (; i < len1 + len2; i++) {
        printf("resNum[%d] %d\n", i, resNum[i]);
        resChar[j++] = resNum[i] + '0';
    }
    resChar[j] = '\0';

    free(resNum);
    return resChar;
}