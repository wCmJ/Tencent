struct Tree{
    int val;
    Tree *left;
    Tree *right;
    Tree(int v):val(v),left(NULL),right(NULL){}
};


//new
bool doesTree1HasTree2(Tree *pRoot1, Tree *pRoot2)
{
    if(pRoot2 == NULL)
        return true;
    if(pRoot1 == NULL)
        return false;
    if(pRoot1->val == pRoot2->val)
        return doesTree1HasTree2(pRoot1->left, pRoot2->left) && doesTree1HasTree2(pRoot1->right, pRoot2->right);
    return false;
}

bool hasSubTree(Tree *pRoot1, Tree *pRoot2)
{
    bool result = false;
    if(pRoot1 != NULL && pRoot2 != NULL)
    {
        if(pRoot1->val == pRoot2->val)
            result = doesTree1HasTree2(pRoot1, pRoot2);
        if(!result)
            result = hasSubTree(pRoot1->left, pRoot2);
        if(!result)
            result = hasSubTree(pRoot1->right, pRoot2);       
    }
    return result;    
}


//first thought
bool compareTwoNode(ListNode *a, ListNode *b)
{
    if(b == NULL)
        return true;
    if(a == NULL)
        return false;
    if(a->val == b->val)
        return compareTwoNode(a->left, b->left) && compareTwoNode(a->right, b->right);
    else
        return false;
}

bool contain(Tree *a, Tree *b)
{
    if(b == NULL || a == NULL)
        return false;
    bool flag = false;
    if(a->val == b->val)
        flag = compareTwoNode(a, b);        
    return flag || contain(a->left, b) || contain(a->right, b);
}
