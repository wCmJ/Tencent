//no duplicated and may be rotated
int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size();
    while(left < right){
        int mid = (left + right)/2;
        int val = (nums[mid] < nums[0] == target < nums[0])?nums[mid]:(target < nums[0]?INT_MIN:INT_MAX);
        if(val == target)
            return mid;
        else if(val < target)
            left = mid + 1;
        else
            right = mid;    
    }
    return -1;
}
