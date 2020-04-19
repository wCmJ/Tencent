//线段树
//求区间和，更新某个节点值的复杂度均为log(n)

const int SIZE = 10000;
class segment_tree{
public:
    segment_tree(int nums[], int size):_size(size?size:1){
        _pData = new int[size?size:1];
        _pData[0] = 0;
        for(int i = 0;i<_size;++i){
            _pData[i] = nums[i];
        }
        memset(_pNode, sizeof(_pNode), 0);
        build_tree(0, 0, _size - 1);
    }
    
    int compute(int L, int R){
        if(R < 0 || L >= _size)return 0;
        return compute(0, 0, _size - 1, L, R);
    }
    void update(int idx, int val){
        if(idx < 0 || idx >= _size)return;
        update(0, 0, _size - 1, idx, val);
    }
private:
    void update(int node, int begin, int end, int idx, int val){
        if(begin > end || idx < begin || end < idx)return;
        _pNode[node] = _pNode[node] - _pData[idx] + val;
        if(begin == end)return;
        int mid = begin + (end - begin) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        update(left_node, begin, mid, idx, val);
        update(right_node, mid + 1, end, idx, val);               
    }
    int compute(int node, int begin, int end, int L, int R){
        if(end < L || begin > R)return 0;
        if(L <= begin && end <= R)return _pNode[node];
        int mid = begin + (end - begin) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        return compute(left_node, begin, mid, L, R) + compute(right_node, mid + 1, end ,L, R);    
    }
    void build_tree(int node, int begin, int end){
        if(begin > end)return;
        if(begin == end){
            _pNode[node] = _pData[begin];
            return;
        }
        
        int mid = begin + (end - begin)/2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build_tree(left_node, begin, mid);
        build_tree(right_node, mid + 1, end);
        _pNode[node] = _pNode[left_node] + _pNode[right_node];    
    }

private:
    int* _pData;
    int _size;
    int _pNode[SIZE];
};

