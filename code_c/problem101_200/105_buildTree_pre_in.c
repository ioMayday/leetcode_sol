/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Good Job，理解到位，一次写对！！！
// 根据前序和中序，构建一个二叉树
struct TreeNode* build(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd)
{
    // base case
    if (inStart > inEnd) return NULL; // 叶子节点

    // root operation
    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    // 前序遍历结果
    root->val = preorder[preStart];
    // 中序遍历来分界
    int i, idx = -1;
    for (i = inStart; i <= inEnd; i++) {
        if(inorder[i] == root->val) {
            idx = i;
            break;
        }
    }

    // 递归生成左右子树
    int leftSize = idx - inStart;
    root->left = build(preorder, preStart + 1, preStart + leftSize,
                      inorder, inStart, idx - 1);
    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                      inorder, idx + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorder == NULL || inorder == NULL) return NULL;

    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}