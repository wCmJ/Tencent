struct listNode{
    int val;
    listNode *next;
    listNode(int v):val(v),next(NULL){}
};

void addToTail(listNode *root, int value){
    if(NULL == root){
        root = new listNode(value);
        return;
    }
    listNode *tmp = root;
    while(NULL != tmp->next){
        tmp = tmp->next;
    }    
    tmp->next = new listNode(value);
}

void removeNode(listNode *root, int value){
    if(NULL == root)return;
    if(root->val == value){
        listNode *del = root;
        root = root->next;
        delete del;
    }
    else{
        listNode *del = NULL;
        while(root->next != NULL && root->next->val != value){
            root = root->next;        
        }
        if(root->next != NULL && root->next->val == value){
            del = root->next;
            root->next = root->next->next;
        }
        delete del;
    }
}


