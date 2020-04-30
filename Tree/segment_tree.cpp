#define MAX_TREE_SIZE 1000
class Segment_tree {
public:
	Segment_tree(int *data, int size) :_size(size <= 0 ? 1 : size) {
		if (data != NULL || size > 0) {
			_arr = new int[_size];
			memset(_tree, sizeof(_tree) / sizeof(int), 0);
			for (int i = 0; i < size; ++i) {
				_arr[i] = data[i];
			}
			build_tree();
		}
	}

	void build_tree() {
		build_tree(0, 0, _size - 1);
	}

	void update_arr(int idx, int value) {
		if (idx < 0 || idx >= _size)return;
		update_arr(idx, value, 0, 0, _size - 1);
	}

	bool get_sum(int idx1, int idx2, int &sum) {
		if (idx1 < 0 || idx1 >= _size || idx2 < 0 || idx2 >= _size)return false;
		sum = 0;
		get_sum(idx1, idx2, 0, 0, _size - 1, sum);
		return true;
	}

private:
	void get_sum(int idx1, int idx2, int node, int begin, int end, int &sum) {
		if (begin > end)return;
		if (begin > idx2 || end < idx1)return;
		if (begin >= idx1 && end <= idx2) {
			sum += _tree[node];
		}
		else {
			int mid = begin + (end - begin) / 2;
			int left_node = 2 * node + 1;
			int right_node = 2 * node + 2;
			get_sum(idx1, idx2, left_node, begin, mid, sum);
			get_sum(idx1, idx2, right_node, mid + 1, end, sum);				
		}
	}

	void update_arr(int idx, int value, int node, int begin, int end) {
		if (begin == end && begin == idx) {
			_arr[idx] = value;
			return;
		}
		if (idx >= begin && idx <= end) {
			_tree[node] = _tree[node] - _arr[idx] + value;
			int mid = begin + (end - begin) / 2;
			int left_node = 2 * node + 1;
			int right_node = 2 * node + 2;
			update_arr(idx, value, left_node, begin, mid);
			update_arr(idx, value, right_node, mid + 1, end);
		}
	}


	void build_tree(int node, int begin, int end) {
		if (begin == end) {
			_tree[node] = _arr[begin];
			return;
		}
		int mid = begin + (end - begin) / 2;
		int left_node  = 2 * node + 1;
		int right_node = 2 * node + 2;
		build_tree(left_node, begin, mid);
		build_tree(right_node, mid + 1, end);
		_tree[node] = _tree[left_node] + _tree[right_node];
	
	}

	int *_arr;
	int _tree[MAX_TREE_SIZE];
	int _size;
};












