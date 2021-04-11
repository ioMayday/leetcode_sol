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
