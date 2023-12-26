// 参考博文：
// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-lian-biao-ti-mu-xun-lian-di-gui-si-wei/di-gui-fan-zhuan-lian-biao-de-yi-bu-fen

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// 先实现整个链表反转 leetcode题206
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) return NULL; // 注意，要先判head是否为空
    if (head->next == NULL) return head;

    struct ListNode* last = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}

// 再实现前n个元素反转
struct ListNode* succesor = NULL;
struct ListNode* reverseN(struct ListNode* head, int n)
{
    if (n == 1) {
        succesor = head->next;
        return head;
    }

    struct ListNode* last = reverseN(head->next, n - 1); //只迭代展开一个，不要压栈出栈
    head->next->next = head;
    head->next = succesor;
    return last;
}

// 再实现从第m到n的两侧均闭区间的反转
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if (head == NULL) return NULL;  // left/right值题目已做限定，默认是正确的

    // 如果left=1,直接是起点
    if (left == 1) {
        return reverseN(head, right);  // left移至1时，right大小等于n个数
    }
    // 否则，移动到对应起点
    head->next = reverseBetween(head->next, left - 1, right - 1); // 返回反转片段新的地点
    return head;
}



//主函数调用
int main()
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
//    struct ListNode* newHead = reverseN(&head, 3);
    struct ListNode* newHead = reverseBetween(&head, 2, 5);
    cur = newHead;
    while (cur != NULL) {
        printf("%d ",cur->val);
        cur = cur->next;
    }
    printf("\n");
	
	return 0;

}