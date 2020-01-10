先排序，再逐个比较

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if(intervals.size() < 1)
        return vector<vector<int>>();
    sort(intervals.begin(),intervals.end(),[](const vector<int> &a, const vector<int> &b){return a[0] < b[0];});
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i= 1;i<intervals.size();++i)
    {
        if(intervals[i][0] <= res[res.size()-1][1])
        {
            res[res.size()-1][1] = max(intervals[i][1], res[res.size()-1][1]);
        }
        else
        {
            res.push_back(intervals[i]);
        }
    }
    return res;
}
