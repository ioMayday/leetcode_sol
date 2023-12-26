// 快慢指针应用
struct ListNode* middleNode(struct ListNode* head)
{
    if (head == NULL) return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) { // 一定要有两步判断才能进行移位
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;  // 节点为偶数时，返回中间靠右侧值
}
