struct BTN{
    BTN *left;
    BTN *right;
    int val;
    BTN(int v):val(v),left(NULL),right(NULL){}
};

void monotonicTraversal(BTN *head)
{
    if(head == NULL)
        return;
    BTN *cur = head;
    BTN *mostRight = NULL;
    while(cur)
    {
        mostRight = cur->left;
        if(mostRight != NULL)
        {
            while(mostRight->right != NULL && mostRight->right != cur)
                mostRight = mostRight->right;
            if(mostRight->right == NULL)
            {
                std::cout<<cur->val<<std::endl;//pre-order
                mostRight->right = cur;
                cur = cur->left;
                continue;
            }
            else
            {
                mostRight->right = NULL;
            }           
        }
        else
        {
            std::cout<<cur->val<<std::endl;//pre-order
        }
        std::cout<<cur->val<<std::endl;//in-order
        postOrder(cur->left);//post-order
        cur = cur->right;
    }
}

void postOrder(BTN *node)
{
    if(node != NULL)
    {
        if(node->right != NULL)
            postOrder(node->right);
        std::cout<<node->val<<std::endl;            
    }
}
