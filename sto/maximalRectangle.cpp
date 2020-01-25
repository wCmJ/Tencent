int getMax(vector<int>& p, int len)
{
	int result = 0;
	stack<int> s;
	for (int i = 0; i < len; ++i)
	{
		while (!s.empty() && p[i] <= p[s.top()])
		{
			int high = p[s.top()];
			s.pop();
			int left = s.empty() ? -1 : s.top();
			result = std::max(result, high * (i - left - 1));
		}
		s.push(i);
	}

	while (!s.empty())
	{
		int right = len;
		int high = p[s.top()];
		s.pop();
		int left = s.empty() ? -1 : p[s.top()];
		result = std::max(result, high * (right - left - 1));
	}
	return result;
}
int maximalRectangle(vector<vector<int>>& matrix) {
	if (matrix.empty() || matrix[0].empty())
		return -1;
	int result = 0;
	vector<int> p(matrix[0].size(), 0);
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			p[j] = (matrix[i][j] == 0) ? 0 : p[j] + 1;
		}

		//get max
		result = std::max(result, getMax(p, matrix[0].size()));
	}
	return result;
}
