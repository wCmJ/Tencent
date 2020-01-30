string longestPalindorme(string s){
    if(s.size() < 2)
        return s;
    int start = 0, end = 0;
    int len = s.size();
    for(int i =0;i<len;++i){
        int left = i, right = i;
        while(left >= 0 && s[left] == s[i])--left;
        while(right < len && s[right] == s[i])++right;
        while(left >= 0 && right < len && s[left] == s[right]){
            --left;
            ++right;
        }
        if(right - left > end - start){
            start = left;
            end = right;
        }
    }
    return s.substr(start + 1, end - start - 1);
}
