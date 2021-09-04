/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**思路：两层遍历，消耗O（N^2）
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    *returnSize = 0; //初始返回大小为0
    
    for (int i=0; i < numsSize; i++) {
        for (int j=i+1; j < numsSize; j++) {
            if (target == (nums[i] + nums[j])) {
                int* ret = (int*)malloc(2*sizeof(int));
                if(ret ==NULL)
                    return NULL;
                
                *returnSize = 2;  //表示数组返回大小
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    
    return NULL;

}