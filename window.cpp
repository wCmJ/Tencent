//窗口内最大值
vector<int> maxOfWindow(vector<int>& nums, int k){
    if(nums.empty() || k <= 1)return nums;
    int len = nums.size();
    deque<int> record;
    vector<int> res;
    for(int i = 0;i<len;++i){
        while(!record.empty() && nums[record.back()] <= nums[i]){
            record.pop_back();
        }
        record.push_back(i);
        if(i >= k - 1){
            while(!record.empty() && (i - record.front() >= k)){
                record.pop_front();
            }
            res.push_back(nums[record.front()]);
        }    
    }
    if(len < k){
        res.push_back(nums[record.front()]);    
    }
    return res;
}
