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
 */

void inorderRecruTraver(struct TreeNode* root, int *res, int* returnSize)
{
    if (root == NULL) { return; }

    inorderRecruTraver(root->left, res, returnSize);
    res[*returnSize] = root->val;
    *returnSize += 1;
    inorderRecruTraver(root->right, res, returnSize);
    return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *res = (int*)malloc(101 * sizeof(int));
    if (res == NULL) { return NULL; }
    *returnSize = 0;
    inorderRecruTraver(root, res, returnSize);
    return res;    
}