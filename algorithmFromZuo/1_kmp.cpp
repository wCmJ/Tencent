the key of KMP algorithm is an array called next;
Array records the maximal length of the common substring of pre set and post set.

void getNext(const string &p, vector<int> &v)
{
    if(p.size() == 0)
        return;
    if(p.size() == 1)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(-1);
    v.push_back(0);
    int i = 2, cn = 0;
    while(i < p.size())
    {
        if(p[i-1] == p[cn])
        {
            v.push_back(++cn);
            ++i;
        }
        else
        {
            if(cn == 0)
                ++i;
            else
                cn = v[cn];
        }
    }
}

int kmp(const string& s, const string &p)
{
    if(s.empty() || p.empty())
        return -1;
    vector<int> v;
    getNext(p, v);
    int i = 0, j = 0;
    while(i < s.size() && j < p.size())
    {
        if(s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
        {
            if(j == 0)
                ++i;
            else
                j = v[j];
        }    
    }
    return j == p.size() ? i - j : -1;
}
