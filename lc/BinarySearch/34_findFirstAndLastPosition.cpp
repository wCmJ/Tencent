void search(vector<int> &nums, int left, int right, int target, vector<int> &v)
{
    if(left >= right)
        return;
    while(left < right){
        //int mid = (left + right)/2;
        int mid = left + (right - left)/2;
        
        if(nums[mid] == target){
            if((mid - 1 < 0 || nums[mid-1] != target) && v[0] == -1){
                v[0] = mid;
            }
            if((mid + 1 >= nums.size() || v[mid+1] != target) && v[1] == -1){
                v[1] = mid;
            }
            if(v[0] == -1)
                search(nums, left, mid, target, v);
            if(v[1] == -1)
                search(nums, mid+1, right, target, v);
            return;                            
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid;
        }               
    }
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> v{-1, -1};
    search(nums, 0, nums.size(), target, v);
    return v;
}
