#include<iostream>
void printIndexLoop(char *p , int len, int index)
{
    if(index >= len)
    {
        std::cout<<p<<std::endl;
        return;
    }
    for(int i =0;i<=9;++i)
    {
        *(p + index) = '0' + i;
        printIndexLoop(p, len, index + 1);    
    }
}
void printOneToN(int n)
{
    if(n < 1)
        return;
    char *p = new char[n+1];
    for(int i = 1;i<=n;++i)
    {
        for(int j = 1; j <= 9;++j)
        {
            *p = '0' + j;
            *(p + i) = '\0';
            printIndexLoop(p, i, 1);
        }
    }
    delete[] p;
}
