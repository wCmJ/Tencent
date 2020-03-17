
vector<vector<int>> lc_77_combine_faster(int n, int k) {
	if (n < 1 || k < 1)return vector<vector<int>>();
	vector<vector<int>> res;
	vector<int> nums(n);
	int index = 0;
	int indexLast = 0;
	int indexLastNext = 0;
	for (int i = 0; i < n; ++i) {
		nums[i] = i + 1;
		res.push_back(vector<int>{i + 1});
	}
	indexLast = res.size() - 1;
	indexLastNext = indexLast;

	for (int i = 1; i < k; ++i) {
		while (index <= indexLast) {
			int len = res[index].size();
			int begin = res[index][len - 1];
			vector<int> ins = res[index];
			for (int j = begin; j < nums.size(); ++j) {
				ins.push_back(nums[j]);
				res.emplace_back(ins);
				ins.pop_back();
				indexLastNext++;
			}
			if (index == indexLast) {
				indexLast = indexLastNext;
				++index;
				break;
			}
			++index;
		}
	}
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return res;
}

void lc_77_combine(const vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res, int begin, int k) {
	if(k == 0){
		res.push_back(tmp);
		return;
	}

	for (int i = begin; i < nums.size(); ++i) {
		tmp.push_back(nums[i]);
		lc_77_combine(nums, tmp, res, i + 1, k - 1);
		tmp.pop_back();
	}
}

vector<vector<int>> lc_77_combine(int n, int k)
{
	if (n < 1 || k < 1)return vector<vector<int>>();
	vector<vector<int>> res;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		nums[i] = i + 1;
	}
	vector<int> tmp;
	lc_77_combine(nums, tmp, res, 0, k);
	//print result
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return res;
}
