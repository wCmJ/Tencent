图：
    顶点：
    
    边：
        任意两个顶点连接起来表示一条边

    邻接矩阵：
        n个顶点 -> n行/n列
        nei[i][j]表示第i个顶点和第j个顶点有一条边
        
        利用0/1表示是否连接
        利用具体的数值可表示对应的权重
        
        有向图
        无向图
        带权图
        
    关联矩阵：
        n个顶点 -> n行
        e条边 -> e列
        con[i][j]表示第i个顶点在第j条边上

    顶点类Node：
        data域：记录自身信息
        入度/出度：与其它顶点的联系
        顶点状态：UNDISCOVERED/DISCOVERED/VISITED
        时间标签：发现时间/访问时间
    
    边类Edge：
        data域：记录自身信息
        边权重：
        边状态：
        
    图类：
        顶点集vector<vector<Node>>：
        边集vector<vector<Edge*>>：
        
    
        BFS:
            可求得当前节点到其它顶点的最小距离
        
        DFS:
            
    
    
    
    
    
    
