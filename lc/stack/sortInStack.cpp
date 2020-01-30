//make s ascending
void sort(stack<int> &s)
{
    if(s.size() < 2)
        return;
    stack<int> op;
    while(!s.empty()){
        int up = s.top();
        s.pop();
        if(op.empty() || up <= op.top()){
            op.push(up);
        }
        else{
            while(!op.empty() && op.top() < up){
                int tmp = op.top();
                op.pop();
                s.push(tmp);
            }
            op.push(up);            
        }                        
    }
    while(!op.empty()){
        s.push(op.top());
        op.pop();
    }
}
