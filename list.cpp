ListNode* valid(ListNode* head, int n){
    if(head == NULL || n < 1)return NULL;
    while(head && --n){
        head = head->next;
    }
    return head;
}
ListNode* swapPairs(ListNode* head) {
    if(head == NULL)return head;
    ListNode* tmp = head, *last = head;
    ListNode** pHead = &head;
    while((last = valid(tmp, 2)) != NULL){
        ListNode* sec = tmp->next;
        *pHead = last;
        tmp->next = last->next;
        pHead = &(tmp->next);
        while(sec != last){
            ListNode* third = sec->next;
            sec->next = tmp;
            tmp = sec;
            sec = third;
        }
        sec->next = tmp;
        tmp = *pHead;
    }
    return head;
}
