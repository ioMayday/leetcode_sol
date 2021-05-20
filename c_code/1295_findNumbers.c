#define BASE_OCT    10
#define EVEN_BASE   2
int GetBitsNum(int val)
{
    int bit = 0;
    while (val != 0) {
        val /= BASE_OCT;
        bit++;
    }
    return bit;
}

int findNumbers(int* nums, int numsSize)
{
    int i;
    int cnt = 0;
    for (i = 0; i < numsSize; i++) {
        int bits = GetBitsNum(nums[i]);
        if (bits % EVEN_BASE == 0) { cnt++; }
    }
    return cnt;
}