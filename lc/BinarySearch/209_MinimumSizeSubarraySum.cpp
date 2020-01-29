//brute force
int bf(vector<int> &nums, int s)
{
    int len = nums.size(), result = INT_MAX;
    for(int i = 0;i<len;++i){
        int sum = nums[i];
        if(sum >= s)
            return 1;
        for(int j = i+1;j<len;++j){
            sum += nums[j];
            if(sum >= s){
                result = min(result, j - i + 1);
                break;
            }
        }    
    }
    return result == INT_MAX ? 0 : result;
}

int minSubArrayLen(vector<int> &nums, int s)
{
    int len = nums.size(), result = INT_MAX;
    int left = 0, sum = 0;
    for(int i = 0;i<len;++i){
        sum += nums[i];
        while(sum >= s){
            result = min(result, i - left + 1);
            sum -= nums[left++];
        }
    }
    return result == INT_MAX ? 0 : result;    
}
