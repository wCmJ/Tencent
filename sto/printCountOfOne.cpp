int printCountOfOne(int num)
{
    int res = 0;
    while(num)
    {
        ++res;
        num &= (num - 1);
    }
    return res;
}
