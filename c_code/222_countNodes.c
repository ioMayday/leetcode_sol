/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int countNodes(struct TreeNode* root){  // 可计算任意二叉树节点总数(包含完全二叉树（满二叉树）)
    if (root == NULL) return 0;
    
    // 满二叉树
    int hl = 1, hr = 1;
    struct TreeNode* l = root->left;
    struct TreeNode* r = root->right;
    while (l != NULL) { // 右子树高度
        l = l->left;
        hl++;
    }
    while (r != NULL) { //左子树高度
        r = r->right;
        hr++;
    }
    if (hl == hr) {  // 若为满二叉树
        return pow(2, hl) - 1; // 满二叉树节点计算：2^depth - 1
    }

    // 普通二叉树
    return 1 + countNodes(root->left) + countNodes(root->right);
}