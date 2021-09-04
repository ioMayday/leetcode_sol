/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// 此题双指针跳出边界条件不熟，需要多练习
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if (head == NULL) return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    int i;
    for (i = 0; i < n; i++) { // 题目输入保证了n小于等于节点数
        fast = fast->next;
    }
    if (fast == NULL) return head->next; // 表示刚好删除顺数第一个头结点

    while (fast->next != NULL) { // 跳出时，slow->next为倒数第n节点
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next; // 取消倒数第n+1个节点指向n个节点，转而指向倒数n-1个节点

    return head;
}