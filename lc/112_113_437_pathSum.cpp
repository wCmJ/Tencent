struct node{
    int val;
    node* left;
    node* right;
    node(int v):val(v),left(NULL),right(NULL){}
};

//判断是否存在一条从根节点到叶节点的和为sum的路径
bool pathSumI(node *root, int sum){
    if(NULL == root)return false;
    if(sum == root->val && NULL == root->left && NULL == root->right)return true;
    return pathSumI(root->left, sum - root->val) || pathSumI(root->right, sum - root->val);
}

//打印出所有满足从根节点到叶子节点和为sum的路径
void pathSumII(node *root, vector<int> &v, int sum){
    if(NULL == root)return;
    v.push_back(root->val);
    if(root->val == sum && NULL == root->left && NULL == root->right){//print
        for(int i = 0;i<v.size();++i){
            std::cout<<v[i]<<" ";
        }
        std::cout<<std::endl;
    }
    pathSumII(root->left, v, sum - root->val);
    pathSumII(root->right, v, sum - root->val);
    v.pop_back();
}

void pathSumII(node *root, int sum){
    vector<int> v;
    pathSumII(root, v, sum);
}

//打印出所有连续节点和为sum的个数
void pathSumIII(node *root, int &count, int sum, bool flag){
    if(NULL == root)return;
    if(root->val == sum)++count;
    if(flag){
        pathSumIII(root->left, count, sum, true);
        pathSumIII(root->right, count, sum, true);        
    }
    pathSumIII(root->left, count, sum - root->val, false);
    pathSumIII(root->right, count, sum - root->val, false);
}
void pathSumIII(node *root, int sum){
    int count = 0;
    pathSumIII(root, count, sum, true);
}
