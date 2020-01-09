含义：在数组中找到相距为k的两个数组成的数组对的个数。

函数形式：int findPairs(vector<int>& nums, int k)
输入分析：nums为空/包含一个元素/包含多个元素，k为负数/0/正数

两个元素的关系，可以利用unordered_map来操作。
int findPairs(vector<int>& nums, int k)
{
    if(k < 0)
        return 0;
    int count = 0;
    unordered_map<int, int> um;
    for(auto c:nums)
        um[c]++;
    for(auto c: um)
    {
        if((!k && c.second > 1) || (k && um.count[c.first + k]))++count;
    }
    return count;
}


