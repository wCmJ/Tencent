#include<vector>
#include<string>
void getNext(const std::string &p, std::vector<int> &v)
{
    if(v.size() == 1)
    {
        v[0] = -1;
        return;
    }
    v[0] = -1;
    v[1] = 0;
    int cn = 0, i = 2;
    while(i < p.size())
    {
        if(p[i-1] == p[cn])
            v[i++] = ++cn;
        else
        {
            if(cn > 0)
                cn = v[cn];
            else
                v[i++] = 0;        
        }        
    }
}

int kmp(const std::string &s, const std::string &p)
{
    if(s.size() < 1 || p.size() < 1)
        return -1;
    std::vector<int> v(p.size(), 0);
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
