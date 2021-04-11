/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 前序遍历
struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return NULL;

    // 先交换
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    // 再递归交换
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// 或后序遍历
// struct TreeNode* invertTree(struct TreeNode* root) {
//     if (root == NULL) return NULL;

//     invertTree(root->left);
//     invertTree(root->right);

//     struct TreeNode* tmp = root->left;
//     root->left = root->right;
//     root->right = tmp;
//     return root;
// }

// // Test：中序遍历无效，
// // 原因：仅相当于只交换了根节点下面一层节点，再下一层时被两次交换，故下层相当于没换
// struct TreeNode* invertTree(struct TreeNode* root) {
//     if (root == NULL) return NULL;

//     invertTree(root->left);
//     struct TreeNode* tmp = root->left;
//     root->left = root->right;
//     root->right = tmp;  // right变成了原left指针
//     invertTree(root->right); // 本质还是root->left下面一层被交换
//     return root;
// }