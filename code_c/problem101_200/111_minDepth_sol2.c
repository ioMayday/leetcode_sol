/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 队列链表结构体 BFS版本
typedef struct QueNode {
    int depth;
    struct TreeNode *node;
    struct QueNode *next;
} QueNodeStru, *pQueNodeStru;

void init(QueNodeStru **handle, int depth, struct TreeNode *node)
{
    (*handle) = (pQueNodeStru)malloc(sizeof(QueNodeStru));
    (*handle)->depth = depth;
    (*handle)->node = node;
    (*handle)->next = NULL;
    return;
}

// BFS法，把节点一层一层遍历，用链表结构串起来
int minDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    // 队列节点初始化
    pQueNodeStru queList, queLevelStart;
    init(&queList, 1, root); // root 深度为1
    queLevelStart = queList;

    // 一边层序遍历，一边入队，同时检验是否到达叶节点得到最小深度
    while (queList != NULL) {
        struct TreeNode *node = queList->node;
        if (node->left == NULL && node->right == NULL) {
            return queList->depth;
        }

        if (node->left != NULL) {
            init(&queLevelStart->next, queList->depth + 1, node->left);
            queLevelStart = queLevelStart->next; // 负责记录每一层的起点
        }
        if (node->right != NULL) {
            init(&queLevelStart->next, queList->depth + 1, node->right);
            queLevelStart = queLevelStart->next;
        }
        queList = queList->next; // 负责记录队列的最新起点
    }

    return -1; // false
}