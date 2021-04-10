/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ret = (int *) malloc( 2 * sizeof(returnSize));
    int i,j;
    for (i = 0; i < numsSize; i++) {
        for (j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ret[0] =  i;
                ret[1] = j;
                *returnSize = 2; //务必要有返回值大小，不然ret数组不知道输出多少个
                return ret;
            }
        }
    }
    return ret;
}