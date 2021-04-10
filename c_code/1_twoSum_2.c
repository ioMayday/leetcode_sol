/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**思路：创建数组副本并排序，夹逼缩小范围，虽然更快，但更消耗内存，消耗O（N）
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct object {
    int val;
    int index; //保留排序后交换顺序后遗失的原数组值对应的下标
};

static int compare(const void *a, const void *b)
{
    return ((struct object *) a)->val - ((struct object *) b)->val;
}

static int * twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    struct object *objs = malloc(numsSize * sizeof(*objs));
    for (i = 0; i < numsSize; i++) {
        objs[i].val = nums[i];
        objs[i].index = i;
    }
    qsort(objs, numsSize, sizeof(*objs), compare); //交换时将每个objs[i]里的两个对象都交换了顺序
    
    int *results = malloc(2 * sizeof(int));
    i = 0;
    j = numsSize - 1;
    while (i < j) {
        int sum = objs[i].val + objs[j].val;
        if (sum < target) {
            i++;
        } else if (sum > target) {
            j--;
        } else {
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            *returnSize = 2;
            return results;
        }
    }
    return NULL;
}



// 2020年9月13日 17:30:54
// 仿造以上思路完成的代码
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ObjNums {
    int val;
    int index;
};

static int cmp(const void* a, const void* b)  //比较入参
{
    return ( *(struct ObjNums *)a ).val - ( *(struct ObjNums *) b).val; //从小到大排序，交换return的a，b则从大到小排序
	
    // 注意仿造的下段语句中 -> 这个符号 只有为 . 才能编译通过
	// return ((struct object *) a)->val - ((struct object *) b)->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *ret = (int *) malloc( 2 * sizeof(int));
    struct ObjNums *sortedNums = (struct ObjNums *) malloc(numsSize * sizeof(*sortedNums));
    int i,j;
    *returnSize = 0; 

    for(i=0; i < numsSize; i++) { // 拷贝副本
        sortedNums[i].val = nums[i];
        sortedNums[i].index = i;
    }
    qsort(sortedNums, numsSize, sizeof(*sortedNums), cmp); // 排序,由小到大

    i = 0;
    j = numsSize - 1;
    while (i < j) { // 夹逼求和，一次循环即可
        //if (sortedNums[(i + j) / 2].val > target) { // 中间数比target大，则折半左侧查找
        //    j = (i + j) / 2 - 1;
		//    continue;   
        //} //以上这个if判断针对有负数在左侧的时候会失效，比如 -3 -2 -1 1 2 3 5， target = 0
        if (sortedNums[i].val + sortedNums[j].val < target) {
            i++; // 右移扩大
        }
        else if (sortedNums[i].val + sortedNums[j].val > target) {
            j--; //
        }
        else {
            ret[0] = sortedNums[i].index;
            ret[1] = sortedNums[j].index;
            *returnSize = 2; // 务必要有返回值大小，不然ret数组不知道输出多少个
            return ret;
        }
    }
    return ret; // 为符合规范，让函数末尾有返回值，其实预设输入满足的条件下，不会运行该语句
}



