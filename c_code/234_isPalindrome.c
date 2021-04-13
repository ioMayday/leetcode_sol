struct ListNode *left;

bool traverse(struct ListNode* right)
{
    if (right == NULL) return 1;
    int res = traverse(right->next);
//    printf("%d ", right->val);

    res = res && (left->val == right->val);
    left = left->next;
    return res;
}

bool isPalindrome(struct ListNode* head){
    left = head;
    return traverse(head);
}
