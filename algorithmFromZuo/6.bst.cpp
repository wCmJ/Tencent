
namespace BST {
	struct node {
		int val;
		node* left;
		node* right;
		node(int i) :val(i), left(NULL), right(NULL) {}
	};

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
