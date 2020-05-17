bool canFinish(int numCourses, vector<vector<int>> prerequisites){
    if(numCourses <= 1)return true;
    queue<int> que;//store nodes of 0-in-degree
    unordered_map<int, int> inDegree;//store every node in degrees
    unordered_map<int, vector<int>> dependents;//key node is pre of nodes in vector
    int cnt = 0;
    for(int i = 0;i<prerequisites.size();++i){
        dependents[prerequisites[i][1]].push_back(prerequisites[i][0]);
        inDegree[prerequisites[i][0]]++;
    }
    for(int i = 0;i<numCourses;++i){
        if(inDegree.count(i) == 0){
            que.push(i);
        }
    }
    
    while(!que.empty()){
        int val = que.front();
        que.pop();
        ++cnt;
        for(int i = 0;i<dependents[val].size();++i){
            if(--inDegree[dependents[val][i]] == 0){
                que.push(dependents[val][i]);
            }
        }        
    }
    return cnt == numCourses;
}



    
