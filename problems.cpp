1.给定一个数组array和一个值n，从第n个元素开始，求出以该元素作为最后一个元素的窗口内的最大值
vector<int> getWindowMax(vector<int>& nums, int n){
    if(nums.size() < n || n < 1)return vector<int>();
    std::deque<int> sorted;
    vector<int> res;
    for(int i = 0;i<nums.size();++i){
        if(sorted.empty()){
            sorted.push_back(i);
        }
        else{
            while(!sorted.empty() && nums[sorted.back()] <= nums[i]){
                sorted.pop_back();
            }
            sorted.push_back(i);
            while(!sorted.empty() && i - sorted.front() > n - 1){
                sorted.pop_front();
            }      
        }
        if(i >= n - 1){
            res.push_back(nums[sorted.front()];
        }
    }
    return res;
}
