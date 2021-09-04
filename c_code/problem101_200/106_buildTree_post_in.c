/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
// Good Job，理解到位，一次写对！！！
// 根据后序和中序，构建一个二叉树
// 在上个105题基础上，改写下标，8min搞定

struct TreeNode* build(int* inorder, int inStart, int inEnd, int* postorder, int postStart, int postEnd)
{
    // base case
    if (inStart > inEnd) return NULL; // 叶子节点

    // root operation
    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    // 后序遍历结果
    root->val = postorder[postEnd];
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
    root->left = build(inorder, inStart, idx - 1,
                      postorder, postStart, postStart + leftSize - 1);
    root->right = build(inorder, idx + 1, inEnd,
                      postorder, postStart + leftSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (postorder == NULL || inorder == NULL) return NULL;

    return build(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}