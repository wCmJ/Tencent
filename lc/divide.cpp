//两个int相除，返回商的值，取整。范围为[INT_MIN,INT_MAX},如果越界，返回INT_MAX
/*
    1. 首先考虑边界条件，越界情况只能出现在除数为±1的时候。所以单独考虑除数为0，-1，1这三种情况
    2. 确定返回值的符号，将除数与被除数转为正数
    3. 利用每次翻倍的做法，减少时间复杂度
*/

long long divide_double(long long vid, long long vis){
    if(vid < vis) return 0;
    long long cnt = 1;
    long long tmp = vis;
    while(tmp + tmp < vid){
        cnt = cnt + cnt;
        tmp = tmp + tmp;    
    }
    return cnt + divide_double(vid - tmp, vis);
}

int divide(int vid, int vis){
    //处理边界情况
    if(vid == 0)return 0;
    if(vis == 1)return vid;
    if(vis == -1){
        if(vid == INT_MIN)return INT_MAX;
        return 0-vid;
    }
    //取得返回值符号
    long long vd = vid, vs = vis;
    bool flag = true;
    if(vd > 0 && vs < 0){
        flag = false;
        vs = 0 - vs;
    }
    else if(vd < 0 && vs >0){
        flag = false;
        vd = 0 - vd;
    }
    else if(vd < 0 && vs < 0){
        vd = 0- vd;
        vs = 0 - vs;
    }
    //计算返回值
    long long res = divide_double(vd,vs);
    return flag ? res : 0 - res;
}

