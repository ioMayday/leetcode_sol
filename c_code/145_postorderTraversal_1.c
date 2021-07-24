/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 µÝ¹éÐ´·¨
 */

void postorderRecruTraver(struct TreeNode* root, int *res, int* returnSize)
{
    if (root == NULL) { return; }

    postorderRecruTraver(root->left, res, returnSize);
    postorderRecruTraver(root->right, res, returnSize);
    res[*returnSize] = root->val;
    *returnSize += 1;
    return;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *res = (int*)malloc(101 * sizeof(int));
    if (res == NULL) { return NULL; }
    *returnSize = 0;
    postorderRecruTraver(root, res, returnSize);
    return res;    
}