//字典树
/*
    记录出现的字符串，判断字符串是否出现
*/


class trie_tree {
public:
	trie_tree() {
		root = new trie_node();
	}
	void insert_str(const string& s) {
		trie_node* tmp = root;
		for (int i = 0; i < s.size(); ++i) {
			int idx = s[i] - 'a';
			if (tmp->next[idx] == NULL) {
				tmp->next[idx] = new trie_node();
				tmp->next[idx]->ch = s[i];
			}
			tmp = tmp->next[idx];
		}
		tmp->flag = true;
	}

	bool check_str(const string& s) {
		trie_node* tmp = root;
		for (int i = 0; i < s.size(); ++i) {
			int idx = s[i] - 'a';
			if (tmp->next[idx] == NULL)return false;
			tmp = tmp->next[idx];
		}
		return tmp->flag;
	}

	void delete_str(const string & s) {
		trie_node* tmp = root;
		for (int i = 0; i < s.size(); ++i) {
			int idx = s[i] - 'a';
			if (tmp->next[idx] == NULL)return;
			tmp = tmp->next[idx];
		}
		tmp->flag = false;
	}


private:
	struct trie_node {
		trie_node* next[26];
		char ch;
		bool flag;
		trie_node() :ch('\0'),flag(false){
			for (int i = 0; i < 26; ++i) {
				next[i] = NULL;
			}
		}
	};
	trie_node* root;
};
