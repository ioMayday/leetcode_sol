/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Ç°Ðò±éÀúµÝ¹éÐ´·¨
#define MAX_NODE_NUM 101

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preorderTraverRecur(struct TreeNode* root, int* returnSize, int *res)
{
    if (root == NULL) { return; }

    res[(*returnSize)++] = root->val;
    preorderTraverRecur(root->left, returnSize, res);
    preorderTraverRecur(root->right, returnSize, res);
    return;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    int *resArr = (int*)malloc(MAX_NODE_NUM * sizeof(int));
    preorderTraverRecur(root, returnSize, resArr);
    return resArr;
}