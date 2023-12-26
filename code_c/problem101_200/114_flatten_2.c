/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 自己的方法,利用先序方法重新建立个树,调试通过

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void firstTraverse1(struct TreeNode* root)
{
    if (root == NULL) return;

    printf("%d ", root->val);
    firstTraverse1(root->left);
    firstTraverse1(root->right);
    return;
}

void firstTraverse2(struct TreeNode* root)
{
    if (root == NULL) return;

    printf("%d ", root->val);
    firstTraverse2(root->right);
    return;
}


struct TreeNode* g_pre;
void firstFlatten(struct TreeNode* root)
{
    if (root == NULL) return;
    
    // 先生成一个节点
    struct TreeNode* node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = root->val;  // copy root
    node->left = NULL;
    g_pre->right = node;
    g_pre = node;

    firstFlatten(root->left);
    firstFlatten(root->right);

    return;
}

// 自己的方法,利用先序遍历来连接节点
void flatten(struct TreeNode* root)
{
    struct TreeNode* newRoot = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newRoot->val = -1;
    newRoot->left = NULL;
    newRoot->right = NULL;
    g_pre = newRoot;

    firstTraverse1(root);  // left and right
    printf("\n");

    firstFlatten(root);
    root = newRoot->right;  // 缺点是,由于接口限制,单独创立的next副本无法返回;
    g_pre->right = NULL;    // 处理完后,所有节点后,最末尾的节点设为NULL
    
    firstTraverse2(root);  // only right
    
    return;
}


int main(void)
{
    struct TreeNode n1, n2, n3, n4, n5, n6;
    n1.val = 1;
    n2.val = 5;
    n3.val = 6;
    n4.val = 7;
    n5.val = 8;
    n6.val = 9;
    n1.left = &n2;
    n1.right = &n5;
    n2.left = &n3;
    n2.right = &n4;
    n3.left = NULL;
    n3.right = NULL;
    n4.left = NULL;
    n4.right = NULL;
    n5.left = NULL;
    n5.right = &n6;
    n6.left = NULL;
    n6.right = NULL;

    flatten(&n1);

    // while (1) { ; }

    return 0;
}