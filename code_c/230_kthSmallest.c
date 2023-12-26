/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
思路：
二叉搜索树的一个重要特征就是，中序遍历的结果是一个从小到大的有序数
所以记录第k个最小元素的方式就是：
中序遍历，然后全局变量记录中序遍历次数，与k值相同的时候退出遍历，返回对应的值
*/

int g_cnt;
int g_val;
void inorderTraverse(struct TreeNode* root, int k)
{
    // 终止条件
    if (root == NULL) {
        return;
    }

    inorderTraverse(root->left, k);

    // 中序操作处
    g_cnt++; // 记录中序遍历次数
    if (g_cnt == k) {
        g_val = root->val;
        return; // 之后不再遍历
    }

    inorderTraverse(root->right, k);
}

int kthSmallest(struct TreeNode* root, int k)
{
    g_cnt = 0;
    g_val = -1;
    inorderTraverse(root, k);
    return g_val;
}