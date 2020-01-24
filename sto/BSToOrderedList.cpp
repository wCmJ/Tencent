#include<stack>
using std::stack;

struct BTN{
    int m_val;
    BTN* m_left;
    BTN* m_right;
    BTN(int v):m_val(v),m_left(NULL),m_right(NULL){}
};

void insertToStack(BTN *root, stack<BTN*> &s)
{
    while(root)
    {
        s.push(root);
        root = root->m_left;    
    }
}

BTN* bstToOrderedList(BTN *root)
{
    BTN res(0), *p = &res;
    stack<BTN*> s;
    while(true)
    {
        insertToStack(root, s);
        if(s.empty())
        {
            break;
        }
        BTN *tmp = s.top();
        s.pop();
        root = tmp->m_right;
        
        p->m_right = tmp;
        tmp->m_left = tmp->m_left ? p : NULL;
        p = tmp;       
    }
    return res.m_right;
}
