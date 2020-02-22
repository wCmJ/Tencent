
namespace BST {
	struct node {
		int val;
		node* left;
		node* right;
		node(int i) :val(i), left(NULL), right(NULL) {}
	};
	//将二叉树按照先序遍历序列化至文件
	void getString(int val, std::string& s) {
		bool flag = val < 0 ? false : true;
		long long tmp = val;
		tmp = flag ? tmp : -tmp;
		do {
			s = s + (char)(tmp % 10 + '0') + "!";
			tmp /= 10;
		} while (tmp);
		if (!flag) {
			s = "-" + s;
		}
	}
	void serialize_preorder_norec(treeNode* root, std::string& s) {
		std::stack<treeNode*> sNode;
		while (true) {
			while (root) {
				getString(root->val, s);
				sNode.push(root->right);
				root = root->left;
			}
			s += "NULL!";			
			while (!sNode.empty() && sNode.top() == NULL) {
				s += "NULL!";
				sNode.pop();
			}
			if (sNode.empty())
				break;
			root = sNode.top();
			sNode.pop();
		}
	}
	void serialize_preorder(treeNode* root, std::string& s) {
		if (root == NULL) {
			s += "NULL!";
			return;
		}
		getString(root->val, s);
		serialize_preorder(root->left, s);
		serialize_preorder(root->right, s);
	}
	void serializeToFile(treeNode* root) {
		//采用先序遍历的方式将二叉树序列化至文件
		FILE* fd = NULL;
		if (fopen_s(&fd, "bst.txt", "w+") != 0) {
			std::cout << "fopen_s error. error number is:" << errno << std::endl;
			return;
		}
		if (fd == NULL) {
			std::cout << "open file bst.txt failed" << std::endl;
			return;
		}
		std::string s = "";
		//pre-order
		serialize_preorder(root, s);
		std::cout << s << std::endl;
		//serialize_preorder_norec(root, s);
		//write to file
		fputs(s.c_str(), fd);
		fclose(fd);
	}

	//将文件中的字符串反序列化为二叉树
	treeNode* getTreeNode(char* cont, int &start) {
		//
		treeNode* node = NULL;
		if (cont[start] == 'N') {
			start += 5;
			return node;
		}
		bool flag = true;
		if (cont[start] == '-') {
			flag = false;
			++start;
		}
		long long num = 0;
		while (cont[start] != '!') {
			num = num * 10 + cont[start] - '0';
			++start;
		}
		++start;
		node = new treeNode(flag ? num : -num);
		node->left = getTreeNode(cont, start);
		node->right = getTreeNode(cont, start);
		return node;
	}

	treeNode* unserializeFromFile(bool &flag) {
		FILE* fd = NULL;
		flag = false;
		if (fopen_s(&fd, "bst.txt", "r+") != 0) {
			return NULL;
		}
		if (fd == NULL) {
			return NULL;
		}
		flag = true;
		char cont[1000];
		fgets(cont, sizeof(cont), fd);
		int start = 0;
		treeNode* res = getTreeNode(cont, start);
		fclose(fd);
		return res;
	}



	string serializeWithoutRecur(node* root) {



	}


	string serialize(node* root) {
		//use pre-order
		string s;
		if (root == NULL) {
			s += "#!";
		}
		else {

			//int to string
			string tmp = "!";
			bool signFlag = root->val < 0 ? true : false;
			int val = root->val;
			do {
				tmp = (char)('0' + val % 10) + tmp;
				val /= 10;
			} while (val);
			if (signFlag) {
				tmp = "-" + tmp;
			}
			s += tmp;

			s += serialize(root->left);
			s += serialize(root->right);
		}
		return s;
	}
	bool getFirstElement(const string & s, int &val, int index, int &last) {
		int  flag = false;
		while (index < s.size()) {
			if ('0' <= s[index] && s[index] <= '9'){
				val = 10 * val + (s[index] - '0');
			}
			else if (s[index] == '-') {
				flag = true;
			}
			else if (s[index] == '#') {
				last = index + 1;
				break;//refer to null
			}
			else if (s[index] == '!') {
				if (flag) {
					val = -val;
				}
				last = index;
				return true;//number;
			}
			++index;
		}
		return false;
	}
	//pre-order unserialize
	/*
		1.get current node
		2.if not null, get left node;if left node is null, get right node;
		3.if null, do nothing
	*/
	node* unserialize(const string& s, int start, int& end) {
		node* root = NULL;
		//get first element from start
		int val = 0;
		bool flag = getFirstElement(s, val, start, end);
		if (flag) {//number
			root = new node(val);
			//if (end + 1 < s.size()) {
				root->left = unserialize(s, end + 1, end);
			//}
			//if (end + 1 < s.size()) {
				root->right = unserialize(s, end + 1, end);
			//}
		}
		return root;
	}

	node* unserialize(const string& s) {
		if (s.empty()) {
			return NULL;
		}
		int end = -1;
		return unserialize(s, 0, end);
	}
	
	//逐行打印二叉树
	void printBst(node* root) {		
		if (root == NULL)
			return;
		std::queue<node*> qu;
		qu.push(root);
		node* last = root;
		node* nlast = root;
		while (true) {
			if (qu.empty())
				break;
			node* tmp = qu.front();
			qu.pop();
			std::cout << tmp->val << " ";
			if (tmp->left) {
				qu.push(tmp->left);
				nlast = tmp->left;
			}
			if (tmp->right) {
				qu.push(tmp->right);
				nlast = tmp->right;
			}
			if (tmp == last) {
				std::cout << std::endl;
				last = nlast;
			}					
		}

	}
	//先序遍历、中序遍历、后序遍历
	void preorder(treeNode* root) {
		if (NULL != root) {
			std::cout << root->val << " ";
			preorder(root->left);
			preorder(root->right);
		}
	}
	void inorder(treeNode* root) {
		if (NULL != root) {
			inorder(root->left);
			std::cout << root->val << " ";
			inorder(root->right);
		}
	}
	void postorder(treeNode* root) {
		if (NULL != root) {
			postorder(root->left);
			postorder(root->right);
			std::cout << root->val << " ";
		}
	}

	void preorderLoop(treeNode* root, std::stack<treeNode*>& s) {
		while (root) {
			std::cout << root->val << " ";//preorder output
			if (root->right)s.push(root->right);
			root = root->left;
		}
	}

	void preorderLoop(treeNode* root) {
		std::stack<treeNode*> s;
		while (true) {
			preorderLoop(root, s);
			if (s.empty())
				break;
			root = s.top();
			s.pop();
		}
	}

	void inorderLoop(treeNode* root, std::stack<treeNode*>& s) {
		while (root) {
			s.push(root);
			root = root->left;
		}
	}
	void inorderLoop(treeNode* root) {
		std::stack<treeNode*> s;
		while (true) {
			inorderLoop(root, s);
			if (s.empty())
				break;
			root = s.top();
			s.pop();
			std::cout << root->val << " ";//inorder output
			root = root->right;
		}
	}
	void postorderLoop(treeNode* root, std::stack<treeNode*>& s, std::stack<int>& data) {
		while (root) {
			data.push(root->val);
			if (root->left)s.push(root->left);
			root = root->right;
		}
	}
	void postorderLoop(treeNode* root) {
		std::stack<treeNode*> s;
		std::stack<int> data;
		while (true) {
			postorderLoop(root, s, data);
			if (s.empty())
				break;
			root = s.top();
			s.pop();
		}
		while (!data.empty()) {
			std::cout << data.top() << " ";//postorder output
			data.pop();
		}
	}
	//莫里斯先序遍历
	void morrisTraversalPreorder(treeNode* root) {
		while (root) {
			treeNode* mostRight = root->left;
			if (mostRight != NULL) {
				while (mostRight->right != NULL && mostRight->right != root) {
					mostRight = mostRight->right;
				}
				if (mostRight->right == NULL) {
					std::cout << root->val << " ";
					mostRight->right = root;
					root = root->left;
					continue;
				}
				else {
					mostRight->right = NULL;
				}
			}
			else {
				std::cout << root->val << " ";
			}
			root = root->right;
		}
	}
	//莫里斯中序遍历
	void morrisTraversalInorder(treeNode* root) {
		while (root) {
			treeNode* mostRight = root->left;
			if (mostRight != NULL) {
				while (mostRight->right != NULL && mostRight->right != root) {
					mostRight = mostRight->right;
				}
				if (mostRight->right == NULL) {//first time
					mostRight->right = root;
					root = root->left;
					continue;
				}
				else {
					mostRight->right = NULL;
					std::cout << root->val << " ";//inorder version-1
				}
			}
			else {
				//
				std::cout << root->val << " ";//inorder version-1
			}
			//std::cout << root->val << " ";//inorder version-2
			root = root->right;
		}
	}
	//莫里斯后续遍历
	void printReverse(treeNode* root) {
		if (root != NULL) {
			if (root->right != NULL) {
				printReverse(root->right);
			}
			std::cout << root->val << " ";
		}
	}
	void morrisTraversalPostorder(treeNode* root) {
		treeNode* tmp = root;
		while (root) {
			treeNode* mostRight = root->left;
			if (mostRight != NULL) {
				while (mostRight->right != NULL && mostRight->right != root) {
					mostRight = mostRight->right;
				}
				if (mostRight->right == NULL) {
					mostRight->right = root;
					root = root->left;
					continue;
				}
				else {
					mostRight->right = NULL;
					//output 
					printReverse(root->left);
				}
			}
			else {

			}
			root = root->right;
		}
		printReverse(tmp);
	}
	//宽度优先遍历
	void bfs(treeNode* root) {
		if (NULL == root)return;
		std::queue<treeNode*> sq;
		sq.push(root);
		while (!sq.empty()) {
			treeNode* tmp = sq.front();
			sq.pop();
			std::cout << tmp->val << " ";
			if (tmp->left)sq.push(tmp->left);
			if (tmp->right)sq.push(tmp->right);
		}
		std::cout << std::endl;
	}
	//深度优先遍历
	void dfs(treeNode* root, std::stack<treeNode*>& s) {
		if (NULL == root)return;
		s.push(root);
		std::cout << root->val << " ";
		dfs(root->left, s);
		dfs(root->right, s);
		s.pop();
	}
	void dfs(treeNode * root) {
		if (NULL == root)return;
		std::stack<treeNode*> s;
		dfs(root, s);
	}
	void test() {
		node* root = new  node(1);
		root->left = new node(2);
		root->right = new node(3);
		//root->left->left = new node(4);
		root->left->right = new node(5);
		root->right->left = new node(6);
		//root->right->right = new node(7);
		printBst(root);
		string seria = serialize(root);
		std::cout << "selialize string is: " << seria << std::endl;
		node* unseria;
		if (!seria.empty()) {
			unseria = unserialize(seria);
			printBst(unseria);
		}
		std::cout << std::endl;
	}
}
