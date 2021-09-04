/*
核心思路：
1、充分理解题目的输入，题目已根据层序输入建好了多叉树
2、从节点结构体定义中，看出每个节点都有个二级指针children存储着下一层子节点的指针数组，numChildren记录下层子节点个数
3、本质与二叉树遍历相同，改造二叉树的遍历模板即可，将left/right子树遍历，换为for循环遍历children指针数组

参考：
https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/solution/rong-yi-li-jie-de-cyu-yan-di-gui-by-sleeeeep/

引申：
思考下本题的迭代法实现？
思考下如何从层序序列输入，构建出这个多叉树？
*/

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE    10000

void PreTraversal(struct Node *root, int *nums, int *pcnt)
{
    // 终止条件
    if (root == NULL) {
        return;
    }

    // 前序操作
    nums[*pcnt] = root->val; // 输出到数组中
    (*pcnt)++;

    // 遍历
    int i;
    for (i = 0; i < root->numChildren; i++) {
        PreTraversal(root->children[i], nums, pcnt);
    }

    return;
}

int *preorder(struct Node *root, int *returnSize)
{
    *returnSize = 0;
    int *nums = (int*)malloc(MAX_SIZE * sizeof(int));
    if (nums == NULL) {
        return NULL;
    }
    int cnt = 0;
    PreTraversal(root, nums, &cnt);
    *returnSize = cnt;
    return nums;
}