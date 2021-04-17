/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 快慢指针
bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) { // 无环时到末尾NULL节点退出
        fast = fast->next->next;   // 步长2
        slow = slow->next;         // 步长1
        if (slow == fast) return true; // 有环
    }
    return false;
}