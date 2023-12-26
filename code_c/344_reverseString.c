void reverseString(char* s, int sSize){
    if (s == NULL) { return; }

    // 运用左右指针，夹逼往中间靠，相互交换
    char tmp;
    int left = 0;
    int right = sSize - 1;
    while (left < right) {
        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
    return;
}