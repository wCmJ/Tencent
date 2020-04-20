//在翻转排序数组中，找出某个值的下标，若不存在，则返回-1

int search(vector<int>& nums, int target){
    if(nums.empty())return -1;
    int len = nums.size();
    if(nums[0] > nums[len - 1]){//tow sorted array
        int i = 0, j = len - 1;
        if(nums[0] <= target){//in first half 
            while(i <= j){
                int mid = i + (j - i) / 2;
                if(nums[mid] == target)return mid;
                if(nums[mid] >= nums[i] && nums[mid] < target){
                    i = mid + 1;
                }
                else{
                    j = mid - 1;
                }            
            }
        }
        else{//in second half
            while(i <= j){
                int mid = i + (j - i) / 2;
                if(nums[mid] == target)return mid;
                if(nums[mid] <= nums[j] && nums[mid] > target){
                    j = mid - 1;
                }
                else{
                    i = mid + 1;
                }            
            }
        }        
    }
    else{//one sorted array
        int i = 0, j = len - 1;//j is the last element
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] > target)j = mid - 1;
            else i = mid + 1;        
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
        if(nums.empty())return -1;
        int len = nums.size();
        if(nums[0] > nums[len - 1]){//tow sorted array
            int i = 0, j = len - 1;
            if(nums[0] <= target){//in first half 
                while(i <= j){
                    int mid = i + (j - i) / 2;
                    if(nums[mid] == target)return mid;
                    if(nums[mid] >= nums[i] && nums[mid] < target){
                        i = mid + 1;
                    }
                    else{
                        j = mid - 1;
                    }            
                }
            }
            else{//in second half
                while(i <= j){
                    int mid = i + (j - i) / 2;
                    if(nums[mid] == target)return mid;
                    if(nums[mid] <= nums[j] && nums[mid] > target){
                        j = mid - 1;
                    }
                    else{
                        i = mid + 1;
                    }            
                }
            }        
        }
        else{//one sorted array
            int i = 0, j = len - 1;//j is the last element
            while(i <= j){
                int mid = i + (j - i) / 2;
                if(nums[mid] == target)return mid;
                else if(nums[mid] > target){
                    j = mid - 1;
                }
                else {
                    i = mid + 1;
                }        
            }
        }
        return -1;
    }

