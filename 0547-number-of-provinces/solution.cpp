class Solution {
    void dfs(int node, vector<int> &visited, unordered_map<int, vector<int>> mpp){
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neigh : mpp[node]){
                if(visited[neigh] == 0){
                    q.push(neigh);
                    visited[neigh] = 1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> mpp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]) mpp[i].push_back(j);
            }
        }


        // do dfs
        int cnt = 0;
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                cnt++;
                dfs(i, visited, mpp);
            }
        }

        return cnt;
    }
};
