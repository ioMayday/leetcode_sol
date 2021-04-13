/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// 递归写法
void flatten(struct TreeNode* root)
{
    if (root == NULL) return;

    // 先得到两个flatten后的左右子树
    flatten(root->left);
    flatten(root->right);

    // 重新接上左右子树
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    // 接上左子树
    root->left = NULL;
    root->right = left;

    // 找到原左子树flatteng的末尾节点
    struct TreeNode* p = root;  //直接从root开始赋值,比root->right赋值要好,省去一个NULL判断
    while (p->right != NULL) { 
        p = p->right;
    }
    // 接上原右子树
    p->right = right; 

    return;
}