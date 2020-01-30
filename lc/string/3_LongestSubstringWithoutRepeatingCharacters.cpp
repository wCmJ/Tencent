int longestSubstringWithoutRepeat(string s){
    int res = 0;
    int index = -1;
    unordered_map<char, int> um;
    int len = s.size();
    for(int i =0;i <len;++i){
        index = max(index, um.count(s[i]) == 0?-1:um[s[i]]);
        res = max(res, i - index);
        um[s[i]] = i;
    }
    return res;
}
