void exchange(string& s, int left, int right){
    int left_end = right, right_end = s.size();
    while(left < left_end && right < right_end){
        char t = s[left];
        s[left] = s[right];
        s[right] = t;
        ++left;
        ++right;
    }
    if(right == right_end){
        right = left_end;
    }
    exchange(s, left, right);
}

void exchange(string& s, int len){
    if(s.size() <= len)return;
    exchange(s, 0, len);
}
