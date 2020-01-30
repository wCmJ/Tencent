int maximumSubarray(vector<int> &nums){
    if(nums.size() < 1)
        return 0;//todo
    vector<int> val(nums.size(), 0);
    val[0] = nums[0];
    int res = nums[0];
    for(int i = 1;i<nums.size();++i){
        val[i] = nums[i] + (val[i-1] > 0 ? val[i-1] : 0);
        res = max(res, val[i]);
    }
    return res;
}
