1.排序
2.在剩下的数中，从两边向中间靠拢，取出合适的值
vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    int len = nums.size();
    for(int i=0;i<len;)
    {
        int left = i+1, right = len - 1;
        int target = 0 - nums[i];
        while(left < right)
        {
            int tmp = nums[left] + nums[right];
            if(tmp < target)
                ++left;
            else if(tmp > target)
                --right;
            else
            {
                int n1 = nums[i];
                int n2 = nums[left];
                int n3 = nums[right];
                res.push_back(vector<int>{n1, n2, n3});
                while(left < len && nums[left] == n2)++left;
                while(right > left && nums[right] == n3)--right;            
            }
        }
        while(i < len && nums[i] == -target)++i;        
    }
    return res;
}


