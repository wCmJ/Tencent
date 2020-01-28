int divisor(int, int);
int multiple(int a, int b)
{
    int tmp = divisor(a, b);
    return a * b / tmp;
}
