/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 快慢指针
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) { // 无环时到末尾NULL节点退出
        fast = fast->next->next;   // 步长2
        slow = slow->next;         // 步长1
        if (slow == fast) break;   // 有环跳出
    }
    if (fast == NULL || fast->next == NULL) {
        return NULL; // 无环
    } 
    // 有环
    fast = head;
    while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow; // 返回第二次相遇的节点
}