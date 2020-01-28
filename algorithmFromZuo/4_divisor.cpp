int divisor(int a, int b)
{
    int tmp;
    if(a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
