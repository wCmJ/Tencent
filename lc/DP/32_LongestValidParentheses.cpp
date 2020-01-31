//(()
//()(()
//)()())(

int longestValidParentheses(const string &s){
    if(s.size() < 2)
        return 0;
    int len = s.size();
    int res = 0;
    vector<int> v(s.size(), 0);
    for(int i = 0;i < len;++i){
        if(s[i] == '('){
            int index = i - 1;
            if(index >= 0){
                index -= v[index];
            }
            if(index >= 0 && s[index] == '('){
                v[i] = v[i-1] + 2 + (index - 1 >= 0 ? v[index-1] : 0);
                res = max(res, v[i]);
            }
        }
    }
    return res;
}
