#include<iostream>
#include<string>
using std::string;

void printPermutation(string &p, int index)
{
    if(p.size() <= index + 1)
    {
        std::cout<<p<<std::endl;
        return;
    }
    for(int i = index;i<p.size();++i)
    {
        char t = p[i];
        p[i] = p[index];
        p[index] = t;
        printPermutation(p, index + 1);
        t = p[i];
        p[i] = p[index];
        p[index] = t;        
    }    
}
void printPermutation(string &p)
{
    if(p.size() < 1)
        return;
    printPermutation(p, 0);
}



