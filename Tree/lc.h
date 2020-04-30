class lc {
	

	void construct_tree_node() {
		/*
					13
			7				19	
		3		10		15		23
			  8		       17		25
		*/
		_root = new tree_node(13);
		_root->left = new tree_node(7);
		_root->left->left = new tree_node(3);
		_root->left->right = new tree_node(10);
		_root->left->right->left = new tree_node(8);

		_root->right = new tree_node(19);
		_root->right->left = new tree_node(15);
		_root->right->left->right = new tree_node(17);
		_root->right->right = new tree_node(23);
		_root->right->right->right = new tree_node(25);
	}

	struct bst_return_node {
		int maxVal;
		int minVal;
		bool isValid;
		bst_return_node(int max, int min, bool valid) :maxVal(max), minVal(min), isValid(valid) {}
	};
public:
	lc() {
		construct_tree_node();
	}
	struct list_node {
		int val;
		list_node* next;
		list_node(int v) :val(v), next(NULL) {}
	};
	struct tree_node {
		int val;
		tree_node* left;
		tree_node* right;
		tree_node(int v) :val(v), left(NULL), right(NULL) {}
	};
	bool isValidBinarySearchTree() {
		if (_root == NULL)return false;
		bst_return_node res = _isValidBinarySearchTree(_root);
		return res.isValid;
	}

	bool isValidBinarySearchTree_inorder() {
		if (_root == NULL)return false;
		return _isValidBinarySearchTree_inorder();
	}

	tree_node* lc_105_pre_in_to_bst(vector<int> &pre, vector<int> &in) {
		if (pre.empty() || pre.size() != in.size())return NULL;
		return _lc_105_pre_in_to_bst(pre, 0, pre.size() - 1, in, 0, in.size() - 1);
	}

	tree_node* lc_109_list_to_bst() {
		//construct list_node
		list_node *ln = new list_node(1);
		ln->next = new list_node(2);
		ln->next->next = new list_node(3);
		ln->next->next->next = new list_node(4);
		ln->next->next->next->next = new list_node(5);
		ln->next->next->next->next->next = new list_node(6);

		return _lc_109_list_to_bst(ln);
	}

	vector<vector<int>> path_sum(int sum) {
		if (_root == NULL)return vector<vector<int>>();
		vector<vector<int>> res;
		vector<int> tmp;
		_path_sum(_root, res, tmp, sum);
		return res;
	}

	void reset_root_node(int val) {
		if (_root == NULL)return;
		_root->val = val;
	}

	tree_node* bst_to_list(){ 
		if (_root == NULL)return NULL;
		std::stack<tree_node*> s;
		tree_node res(0), *p_res = &res;
		tree_node* tmp = _root;
		while (true) {
			while (tmp) {
				p_res->right = tmp;
				p_res->left = NULL;
				p_res = p_res->right;
				if (tmp->right)s.push(tmp->right);
				tmp = tmp->left;
			}
			if (s.empty())break;
			tmp = s.top();
			s.pop();
		}
		return res.right;
		return _bst_to_list(_root);
	}

private:
	tree_node* _lc_109_list_to_bst(list_node* ln) {
		if (ln == NULL)return NULL;
		if (ln->next == NULL)return new tree_node(ln->val);
		tree_node* res;
		list_node* slow = ln, *fast = ln;
		list_node* pre = NULL;
		while (fast && fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		if (pre)pre->next = NULL;
		res = new tree_node(slow->val);
		res->left = _lc_109_list_to_bst(ln);
		res->right = _lc_109_list_to_bst(slow->next);
		return res;
	}


	tree_node* _lc_105_pre_in_to_bst(vector<int>& pre, int p1, int e1, vector<int>& in, int p2, int e2) {
		if (p1 > e1 || p2 > e2)return NULL;
		tree_node* res = NULL;
		int val = pre[p1];
		res = new tree_node(val);
		int mid2 = -1;
		for (int i = p2; i <= e2; ++i) {
			if (in[i] == val) {
				mid2 = i;
				break;
			}
		}
		if (mid2 == -1) {
			//error
			throw std::string("number error");
			return NULL;
		}
		res->left = _lc_105_pre_in_to_bst(pre, p1+1, p1 + (mid2- p2), in, p2, mid2 - 1);
		res->right = _lc_105_pre_in_to_bst(pre, p1 + (mid2-p2) + 1, e1, in, mid2 + 1, e2);
		return res;
	}

	tree_node* _bst_to_list(tree_node* node) {
		if (node == NULL)return NULL;
		if (node->left == NULL) {
			_bst_to_list(node->right);
			return node;
		}
		tree_node* left = node->left;
		tree_node* right = node->right;
		node->left = NULL;
		node->right = left;
		_bst_to_list(node->left);


		return node;
	}


	bool _isValidBinarySearchTree_inorder() {
		std::stack<tree_node*> s;
		int bef = INT_MIN;
		tree_node* tmp = _root;
		while (true) {
			while (tmp) {
				s.push(tmp);
				tmp = tmp->left;
			}
			if (s.empty())break;
			tmp = s.top();
			s.pop();
			std::cout << tmp->val << " ";
			if (bef >= tmp->val) {
				std::cout << std::endl;
				return false;
			}
			bef = tmp->val;
			tmp = tmp->right;
		}
		std::cout << std::endl;
		return true;
	}

	void _path_sum(tree_node* node, vector<vector<int>>& res, vector<int>& tmp, int sum) {
		if (node == NULL)return;
		if (node->val == sum && node->left == NULL && node->right == NULL) {
			tmp.push_back(node->val);
			res.push_back(tmp);
			tmp.pop_back();
			return;
		}
		tmp.push_back(node->val);
		_path_sum(node->left, res, tmp, sum - node->val);
		_path_sum(node->right, res, tmp, sum - node->val);
		tmp.pop_back();
	}

	bst_return_node _isValidBinarySearchTree(tree_node* root) {
		if (root == NULL) {
			return bst_return_node(INT_MIN, INT_MAX, true);
		}

		bst_return_node left_res = _isValidBinarySearchTree(root->left);
		bst_return_node right_res = _isValidBinarySearchTree(root->right);
		int tmp_min = std::min(std::min(left_res.minVal, right_res.minVal), root->val);
		int tmp_max = std::max(std::max(left_res.maxVal, right_res.maxVal), root->val);
		if (left_res.isValid && right_res.isValid && left_res.maxVal < root->val && root->val < right_res.minVal) {			
			return bst_return_node(tmp_max,tmp_min,true);
		}
		return bst_return_node(tmp_max, tmp_min, false);
	}
	tree_node *_root;
};
