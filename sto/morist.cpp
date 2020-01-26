struct BTN{
    int m_val;
    BTN *left;
    BTN *right;
    BTN(int v):m_val(v),left(NULL),right(NULL){}
};

void morist(BTN *root)
{
    if(root == NULL)
        return;
    BTN *cur = root;
    BTN *lastRight = NULL;
    while(cur)
    {
        lastRight = cur->left;
        if(lastRight != NULL)
        {
            while(lastRight->right != NULL && lastRight->right != cur)
                lastRight = lastRight->right;
            if(lastRight->right == NULL)
            {
                //pre
                cout<<cur->val<<endl;
                lastRight->right = cur;
                cur = cur->left;
                continue;
            }
            else
            {
                lastRight->right = NULL;
            }            
        }        
        else
        {
            //pre
            cout<<cur->val<<endl;
        }
        //in
        cout<<cur->val<<endl;
        cur = cur->right;    
    }
}



