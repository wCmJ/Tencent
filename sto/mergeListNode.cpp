struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v):val(v),next(NULL){}
};
ListNode* merge(ListNode *l1, ListNode *l2)
{
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    ListNode *head = NULL;
    if(l1->val < l2->val)
    {
        head = l1;
        head->next = merge(l1->next, l2);    
    }
    else
    {
        head = l2;
        head->next = merge(l1, l2->next);    
    }
    return head;
}
