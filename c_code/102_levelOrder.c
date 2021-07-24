
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int g_curLevelCnt;

typedef struct QueNode { // BFS必备队列链表数据结构
    int depth;
    struct TreeNode *node;
    struct QueNode *next;
} StruQueNode;

typedef struct LevelNode { // BFS必备队列链表数据结构
    int depth;
    int cnt;
    struct LevelNode *next;
} StruLevelNode;

void InitQueList(StruQueNode **queList, struct TreeNode* node, int depth)
{
    *queList = (StruQueNode *)malloc(sizeof(StruQueNode));
    if (*queList == NULL) {
        return;
    }
    (*queList)->depth = depth;
    (*queList)->node = node;
    (*queList)->next = NULL;
    g_curLevelCnt++;
    return;
}

void InitLevelList(StruLevelNode **levelList, int depth, int cnt)
{
    *levelList = (StruLevelNode *)malloc(sizeof(StruLevelNode));
    if (*levelList == NULL) {
        return;
    }
    (*levelList)->depth = depth;
    (*levelList)->cnt = cnt;
    (*levelList)->next = NULL;
    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        *returnSize = 0; // 保证[]空输入时，三个输出值都为0或空
        returnColumnSizes = NULL;
        return NULL;
    }

    StruQueNode *queList, *queListHead, *queLastNode;
    InitQueList(&queList, root, 1);
    queLastNode = queList;
    queListHead = queList;
    StruLevelNode *levelList, *levelListHead, *levelLastNode;
    InitLevelList(&levelList, 1, 1);
    levelLastNode = levelList;
    levelListHead = levelList;

    // BFS
    int depth = 1;
    struct TreeNode* node;
    while (queList != NULL) {
        // 当前层遍历
        g_curLevelCnt = 0;
        while (queList != NULL && depth == queList->depth) {
            node = queList->node;
            if (node->left != NULL) {
                InitQueList(&queLastNode->next, node->left, depth + 1);
                queLastNode = queLastNode->next; // 记录队列Add尾部节点
            }
            
            if (node->right != NULL) {
                InitQueList(&queLastNode->next, node->right, depth + 1);
                queLastNode = queLastNode->next;
            }

            queList = queList->next; // 当前层下一个节点
        }
        if (queList != NULL) {
            depth++; // 完整遍历完一层，若是queList==NULL则最后一层遍历完没有下一层，则不用再加一
        }

        // 记录当前层节点数
        InitLevelList(&levelList->next, depth, g_curLevelCnt);
        levelList = levelList->next;
    }
    *returnSize = depth;
    // printf("%d\n", depth);

    // 申请对应大小的二维数组并分配空间
    *returnColumnSizes = (int *)malloc(depth * sizeof(int));
    if (*returnColumnSizes == NULL) {
        return NULL;
    }
    int **resArr = (int **)malloc(depth * sizeof(int*));
    if (resArr == NULL) {
        return NULL;
    }

    // 将遍历各层的值push到数组中保存
    int *p;
    int i;
    queList = queListHead;
    levelList = levelListHead;
    depth = 1;
    while (queList != NULL) {
        (*returnColumnSizes)[depth - 1] = levelList->cnt;
        p = (int*)malloc(levelList->cnt * sizeof(int));
        if (p == NULL) {
            return NULL;
        }
        resArr[depth - 1] = p;

        // 当前层遍历
        for (i = 0; i < levelList->cnt; i++) {
            node = queList->node;
            resArr[depth - 1][i] = node->val;
            queList = queList->next; // 当前层下一个节点
        }
        depth++; // 遍历完一层
        levelList = levelList->next;
    }

    return resArr;
}