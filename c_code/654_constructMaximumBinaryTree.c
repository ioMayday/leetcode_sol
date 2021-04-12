/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 // 闭区间 [left, right]
struct TreeNode* buildMaxTree(int* nums, int left, int right) 
{
    // base case
    if (left > right) return NULL;

    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    // 找到最大值做当前的根节点
	// debug code
    // int i, idx, maxVal = nums[left];
    // for (i = left + 1; i <= right; i++) { // 会报内存越界，待查看bug;  =>需同步初始化idx=left
	// right code
	// int i, idx = left, maxVal = nums[left]; // 需同步初始化idx=left
    // for (i = left + 1; i <= right; i++) {   // 否则会报内存越界 

    int i, idx, maxVal = INT_MIN;
    for (i = left; i <= right; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            idx = i;
        }
    }
    root->val = maxVal;

    // 递归调用生成左右子树
    root->left = buildMaxTree(nums, left, idx - 1);
    root->right = buildMaxTree(nums, idx + 1, right);

    return root;
}


struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    if (nums == NULL) return NULL;

    return buildMaxTree(nums, 0, numsSize - 1);

}