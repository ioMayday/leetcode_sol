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

// 前序遍历迭代写法
// 相对于中序遍历的迭代方法，只需要调整打印输出语句的位置即可
#define MAX_NODE_NUM 101

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int i = 0;
    int top = 0; // top记录着栈中元素个数
    int *resArr = (int*)malloc(MAX_NODE_NUM * sizeof(int));
    struct TreeNode** stkNodeArr = (struct TreeNode**)malloc(MAX_NODE_NUM * sizeof(struct TreeNode*));

    while (root != NULL || top > 0) { // 结束条件为到末尾节点底部，且遍历节点栈中都已出栈
        while (root != NULL) { // 先根节点左侧子树
            stkNodeArr[top++] = root; // 入栈记录过程节点
            resArr[i++] = root->val; // 入栈时就输出记录，相当于前序遍历
            root = root->left;
        } // 到达左侧叶节点的NULL

        // 取出栈顶节点，也即叶节点
        root = stkNodeArr[--top];
        // 叶节点右侧子树
        root = root->right;
    }

    *returnSize = i;
    free(stkNodeArr);

    return resArr;
}