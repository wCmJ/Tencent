

enum NODESTATUS{
        UNDISCOVERED = 0,
        DISCOVERED,
        VISITED
    };
struct NODE{
    NODESTATUS status;
    int indegree;
    int outdegree;
    NODE():status(UNDISCOVERED),indegree(0), outdegree(0){}
};

class Graph{
/*
    
*/
private:
    int nSize;
    vector<NODE> v;
    vector<vector<int>> neiVer;
    int nextNeighbor(int node, int cur){
        while(--cur >= 0 && neiVer[node][cur] == 0);
        return cur;
    }
    int firstNeighbor(int node){
        return nextNeighbor(node, nSize);
    }
    
public:
    vector<int> BFS(int node){
        if(node < 0 || node >= nSize)return vector<int>();
        vector<int> res;
        std::deque<int> dq;
        dq.push_back(node);
        v[node].status = DISCOVERED;
        while(!dq.empty()){
            int tmp = dq.front();
            dq.pop_front();
            {
                std::cout<<node<<std::endl;//process node
                res.push_back(tmp);               
            }
            for(int i = firstNeighbor(tmp);i!=-1;i=nextNeighbor(tmp,i)){
                if(v[i].status == UNDISCOVERED){
                    v[i].status = DISCOVERED;
                    dq.push_back(i);
                }
                else{
                    //   
                }
            }
            v[tmp].status = VISITED;
        }   
        return res;
    }

    vector<int> DFS(int node){
        if(node < 0 || node >= nSize)return vector<int>();
        std::stack<int> s;
        vector<int> res;
        s.push(node);
        res.push_back(node);
        while(!s.empty()){
            int next = nSize;
            int tmp = s.top();
            while((next = nextNeighbor(tmp, next)) != -1 && v[next] != UNDISCOVERED);
            if(next != -1){
                v[next] = DISCOVERED;
                s.push(next);
                res.push_back(next);
            }
            else{
                v[tmp] = VISITED;
                s.pop();
            }
        }
        return res;        
    }
    
};




