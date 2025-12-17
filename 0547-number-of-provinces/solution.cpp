class Solution {
    void dfs(vector<vector<int>>& isConnected, int node, vector<int> &visited){
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0; i<isConnected[node].size(); i++){
                if(isConnected[node][i] && visited[i] == 0){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // without creating adjlist, uisng index as nodes 
        int n = isConnected.size();
        vector<int> visited(n, 0);

        int noOfProvinces = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                visited[i] = 1;
                dfs(isConnected, i, visited);
                noOfProvinces++;
            }
        }

        return noOfProvinces;
    }
};
