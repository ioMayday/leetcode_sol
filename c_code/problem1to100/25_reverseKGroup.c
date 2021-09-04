// 先迭代法实现一个链表逆序
struct ListNode* reverse(struct ListNode* head)
{
    if (head == NULL) return NULL;

    struct ListNode *pre, *cur, *nxt;
    pre = NULL;
    cur = head;
    while (cur != NULL) {
        nxt = cur->next;
        // 反转一个节点
        cur->next = pre;
        pre = cur; // 指针移位
        cur = nxt;
    }

    return pre;
}

// 迭代法实现链表的区间逆序 [a, b)
struct ListNode* reverseInterval(struct ListNode* a, struct ListNode* b)
{
    if (a == NULL) return NULL;

    struct ListNode *pre, *cur, *nxt;
    pre = NULL;
    cur = a;
    while (cur != b) {
        nxt = cur->next;
        // 反转一个节点
        cur->next = pre;
        pre = cur; // 指针移位
        cur = nxt;
    }

    return pre;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (head == NULL) return NULL;

    // 先移动k个指针
    int i;
    struct ListNode *a, *b;
    a = b = head;
    for (i = 0; i < k; i++) {
        if (b == NULL) return head; // base case，不足k个的直接返回head，不操作
        b = b->next;
    }

    // 逆序前k个
    struct ListNode* newHead = reverseInterval(a, b); // 注意区间左闭右开，[a, b)

    // 递归调用KGroup继续逆序
    head = reverseKGroup(b, k); // 从b开始，作为子链表递归求解

    // 连接上两个链表
    a->next = head;

    return newHead;
}