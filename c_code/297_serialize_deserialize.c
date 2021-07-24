/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 前序遍历实现，设计类题目
// 其他思路：后序遍历、层序遍历实现
#define STR_MAX_SIZE 1000000

void serializeTree(struct TreeNode* root, char *s)
{
    if (root == NULL) {
        char *nul = "#,";
        strcat(s, nul);
        return;
    }

    // 前序操作区
    char tmp[10] = {0};
    sprintf(tmp, "%d,", root->val);
    strcat(s, tmp);

    // 遍历区
    serializeTree(root->left, s);
    serializeTree(root->right, s);
    return;
}

struct TreeNode* deserializeTree(char **next, char *split)
{
    if (*next == NULL) {
        return NULL;
    }

    // 前序操作区
    char *head = *next;
    char *str = strtok_r(NULL, split, next);
    if (str == NULL || *str == '#') {
        return NULL;
    }
    // printf("%s\n", str);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    root->val = atoi(str);
    root->left = deserializeTree(next, split);
    root->right = deserializeTree(next, split);

    return root;
}

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root)
{
    if (root == NULL) {
        return NULL;
    }

    char *res = (char*)malloc(sizeof(char) * STR_MAX_SIZE);
    if (res == NULL) {
        return NULL;
    }
    memset(res, 0, STR_MAX_SIZE);

    serializeTree(root, res);

    // printf("%s\n", res);

    return res;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data)
{
    if (data == NULL) {
        return NULL;
    }

    char split[2] = ",";
    char *next = NULL;
    char *str;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    str = strtok_r(data, split, &next);
    if (str == NULL || *str == '#') {
        return NULL;
    }
    root->val = atoi(str);
    root->left = deserializeTree(&next, split);
    root->right = deserializeTree(&next, split);

    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);

