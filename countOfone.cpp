
int countOfOne(int n){
    if(n < 1) return 0;
    int res = 0, left = 0;
    long long factor = 1;
    while(n){
        int val = n % 10;
        if(val < 1){
            res += tmp / 10 * factor;
        }
        else if(val == 1){
            res += tmp / 10 * factor + left + 1;
        }
        else{
            res += (tmp / 10 + 1) * factor;
        }
        left += val * factor;
        factor *= 10;
        n /= 10;
    }
    return res;
}




