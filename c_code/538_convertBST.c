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
累加树的中序遍历结果是从大到小的有序数组

转换的方式：
依然是中序遍历
只是先遍历右子树
从而先得到最小值
然后在中序位置处不断递归累加前一个中序遍历结果
*/

struct TreeNode* preNode;
void inorderTraverse(struct TreeNode* root)
{
    // 终止条件
    if (root == NULL) { // 到叶节点的子节点或者右侧叶节点时直接返回
        return;
    }

    inorderTraverse(root->right);

    // 处理当前节点，与前一个节点的值相加
    if (preNode != NULL) { // 等于NULL时，即表示到右侧叶节点，无前继节点，则不操作val
        root->val += preNode->val;
    }
    preNode = root; // 记录中序遍历时，当前节点的前一个节点

    inorderTraverse(root->left);

    return;
}

struct TreeNode* convertBST(struct TreeNode* root)
{
    preNode = NULL;
    inorderTraverse(root);
    return root;
}