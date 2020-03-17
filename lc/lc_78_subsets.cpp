
void lc_78_subsets(const vector<int>& nums, vector<int> &tmp, vector<vector<int>> &res, int begin, int n) {
	if (n == 0) {
		res.push_back(tmp);
		return;
	}

	for (int i = begin; i < nums.size(); ++i) {
		tmp.push_back(nums[i]);
		lc_78_subsets(nums, tmp, res, i + 1, n - 1);
		tmp.pop_back();
	}
}


//1 2 3 4
vector<vector<int>> lc_78_subsets(vector<int>& nums) {
	if (nums.empty())return vector<vector<int>>();
	vector<vector<int>> res;
	vector<int> tmp;
	for (int i = 1; i <= nums.size(); ++i) {
		lc_78_subsets(nums, tmp, res, 0, i);
	}

	//print result
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return res;
}
