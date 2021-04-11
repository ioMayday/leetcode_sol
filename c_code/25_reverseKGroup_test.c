// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


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

int main(void)
{
    struct ListNode head, p2, p3, p4, p5;
    head.val = 1;
    head.next = &p2;
    p2.val = 2;
    p2.next = &p3;
    p3.val = 3;
    p3.next = &p4;
    p4.val = 4;
    p4.next = &p5;
    p5.val = 5;
    p5.next = NULL;

    // 初始化后遍历显示
    struct ListNode *cur, *pre, *nxt;
    cur = &head;
    while (cur != NULL) {
        printf("%d ",cur->val);
        cur = cur->next;
    }
    printf("\n");


    // 反转后遍历显示
//    struct ListNode* newHead = reverse(&head);
//    struct ListNode* newHead = reverseInterval(&p2, &p5);
    struct ListNode* newHead = reverseKGroup(&head, 2);

    cur = newHead;
    while (cur != NULL) {
        printf("%d ",cur->val);
        cur = cur->next;
    }
    printf("\n");

    return 0;
}
