//并查集
/*
    可用于判断图是否有环
    根据图的邻接矩阵来构造_parent，构造过程中，可根据connect返回值判断是否有环
*/

class disjoint_set{
public:
    disjoint_set(vector<vector<bool>>& neigbor, int size):_size(size?size:1){
        _parent = new int[_size];
        for(int i = 0;i<_size;++i){
            _parent[i] = i;
        }
        //construct
        for(int i = 0;i<neigbor.size();++i){
            for(int j = 0;j<neigbor[i].size();++j){
                if(neigbor[i][j] && (connect(i, j) == 1)){
                    //有环
                }        
            }
        }
    }
    
    int parent(int idx){
        if(idx < 0 || idx >= _size)return -1;
        while(_parent[idx] != idx){
            idx = _parent[idx];
        }
        return idx;
    }

    int connect(int x, int y){
        if(x <0 || x >= _size || y < 0 || y >= _size)return -1;
        int x_parent = parent(x);
        int y_parent = parent(y);
        if(x_parent == y_parent){
            return 1;//有环
        }
        _parent[x_parent] = y_parent;
        return 0;//无环
    }
    
    bool isConnectted(int x, int y){
        if(x <0 || x >= _size || y < 0 || y >= _size)return false;
        return parent(x) == parent(y);
    }

private:
    int *_parent;
    int _size;

};
