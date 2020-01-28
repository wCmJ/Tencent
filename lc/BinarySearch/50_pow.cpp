double myPow(double x, int n)//make sure x != 0 && n >= 0
{
    if(n == 0)
        return 1;
    return ((n & 0x01) == 0) ? myPow(x*x, n/2) : x * myPow(x*x, n/2);        
}

int pow(int x, int n)
{
    if(x == 0)
        return 0;
    bool flag = (n < 0) ? true : false;
    long ln = n;
    ln = (ln < 0)?-ln:ln;
    long res = myPow(x, ln);
    if(flag)
        res = 1/res;
    return res;
}
