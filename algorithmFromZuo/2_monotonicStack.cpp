monotonic stack is a stack that keeps values with the fixed order.

example:
    1   0   0   1   1
    1   1   0   1   1
    0   0   1   1   1
    
    get the maximal numbers of rectangle with all '1'
    
    1. we get the array of every line as bottom
    
        first line numbers:
            1   0   0   1   1
        second line numbers:
            2   1   0   2   2
        third line numbers:
            0   0   1   3   3
    2. use monotonic stack to every line numbers:
        
codes:
    int maxOfMonotonicStack(const vector<int> &nums)
    {
        int result = 0;
        stack<int> s;
        for(int i = 0;i<nums.size();++i)
        {
            while(!s.empty() && nums[i] <= nums[s.top()])
            {
                int high = nums[s.top()];
                s.pop();
                int right = i;
                int left = s.empty() ? -1 : s.top();
                result = max(result, high * (right - left - 1));                                       
            }
            s.push(i);
        }
        while(!s.empty())
        {
            int high = nums[s.top()];
            s.pop();
            int right = nums.size();
            int left = s.empty() ? -1 : s.top();
            result = max(result, high * (right - left - 1));                                                               
        }
        return result;
    }
    int maxOfRectangle(const vector<vector<char>> v)
    {
        if(v.empty() || v[0].empty())
            return 0;
        vector<int> nums(v[0].size(), 0);
        int result = 0;
        for(int i = 0;i<v.size();++i)
        {
            //get line numbers;
            for(int j = 0;j < v[i].size();++j)
            {
                if(v[i][j] == '0')
                    nums[j] = 0;
                else
                    nums[j] += 1;
            }
            result = max(result, maxOfMonotonicStack(nums));
        }
        return result;
    }

