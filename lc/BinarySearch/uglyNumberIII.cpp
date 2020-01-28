int gcd(int a, int b)
{
    int tmp;
    if(a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int uglyNumber(int n, int a, int b, int c)
{
    int left = 1, right = n * a + 1;
    long ab = ((long)a * b)/gcd(a, b);
    long ac = ((long)a * c)/gcd(a, c);
    long bc = ((long)b * c)/gcd(b, c);
    long abc = (ab * c)/gcd(ab, c);
    while(left < right){
        int mid = (left + right) >> 1;
        int num = mid/a + mid/b + mid/c - mid/ab - mid/ac - mid/bc + mid/abc;
        if(num < n){
            left = mid + 1;
        }
        else
            right = mid;    
    }
    return left;
}



