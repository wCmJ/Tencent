给出一个数组范围0~n,给定一个值k：0~9
算出这个范围的数中包含k的总个数。

int numberOfK(int k, int n){
    if(k < 0 || 9 < k || n < 0){
        return -1;
    }
    if(k == n){
        return 1;
    }
    int count = 0;
    int value = n;
    int sum = 1;
    int n_tmp = -1;
    while(value != 0){
        int tmp = value % 10;
        if(tmp > k){
            count += value / 10 * sum + sum;
        }
        else if(tmp == k){
            count += value / 10 * sum + n - value * sum + 1;
        }
        else{
            count += value / 10 * sum;
        }
        value /= 10;
        sum *= 10;
        n_tmp += sum;
    }
    if(0 == k){
        count -= n_tmp;
    }
    return count;
}

