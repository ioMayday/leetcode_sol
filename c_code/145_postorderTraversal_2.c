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
 迭代写法
 */

#define MAX_NODE_NUM 101

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int i = 0;
    int top = 0; // top记录着栈中元素个数
    int *resArr = (int*)malloc(MAX_NODE_NUM * sizeof(int));
    struct TreeNode** stkNodeArr = (struct TreeNode**)malloc(MAX_NODE_NUM * sizeof(struct TreeNode*));
    struct TreeNode* pre = NULL;

    while (root != NULL || top > 0) { // 结束条件为到末尾节点底部，且遍历节点栈中都已出栈
        while (root != NULL) { // 先根节点左侧子树
            stkNodeArr[top++] = root; // 入栈记录过程节点
            root = root->left;
        } // 到达左侧叶节点的NULL

        // 取栈顶节点，也即叶节点
        root = stkNodeArr[--top];
        printf("%d ", root->val);
        // right 为NULL时，说明右子树已经遍历完
        // right 为pre时，说明逆序到根节点处，右子树已输出，待输出根节点
        if (root->right == NULL || root->right == pre) { // 后序输出  
            resArr[i++] = root->val;
            pre = root; // 后序输出的情况，输出root根1时，上一个输出的必然是当前根的右节点
            root = NULL;
        } else { // root->right != NULL && root->right != pre
            // 否则继续读取叶节点右侧子树,并压栈
            stkNodeArr[top++] = root; // 如果不能输出，则又把root压栈回去
            root = root->right;
        }
    }

    *returnSize = i;
    free(stkNodeArr);

    return resArr;  
}