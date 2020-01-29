//ignore first space and last space and duplicate space between words.
string reverse(string s)
{
    int len = s.size();
    string res;
    //first space
    int i = 0;
    while(i<len && s[i] == ' '){
        ++i;
    }
    
    //last space
    int j = len - 1;
    while(j>=0 && s[j] == ' '){
        --j;
    }
        
    //reverse all words
    int ti = i, tj = j;
    while(ti < tj){
        char t = s[ti];
        s[ti] = s[tj];
        s[tj] = t;
    }
    
    //copy word
    for(;i<=j;){
        //get word
        int index = i;
        while(i<=j && s[i] != ' '){
            ++i;
        }
        for(int k = i - 1;k >= index;--k){
            res += s[k];
        }
        if(i <= j){
            res += ' ';
        }
        while(i<=j && s[i] == ' '){
            ++i;
        }
    }
    return res;
}
