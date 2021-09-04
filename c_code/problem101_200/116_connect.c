/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

// 参考: 此题不熟，需要多练
// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-er-cha-shu-xun-lian-di-gui-si-wei/er-cha-shu-xi-lie-1

void connectTwoNodes(struct Node* node1, struct Node* node2) 
{
    if (node1 == NULL || node2 == NULL) return;

    // 连接左右两个节点
    node1->next = node2;

    // 连接同一父节点下两个节点
    connectTwoNodes(node1->left, node1->right);
    connectTwoNodes(node2->left, node2->right);
    // 连接不同父节点下两个相邻节点
    connectTwoNodes(node1->right, node2->left);
}

struct Node* connect(struct Node* root) {
	if (root == NULL) return root;

    connectTwoNodes(root->left, root->right);

    return root;
}