class Solution {
    bool bfs(vector<vector<int>>& adjList, int node, vector<int> &visited,  vector<int> &color){
        queue<pair<int, int>> q;
        q.push({node,node});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(int neigh : adjList[node]){
                if(!visited[neigh]){
                    visited[neigh] = 1;
                    color[neigh] = !color[node];
                    q.push({neigh, node}); // {node and its parent}
                }
                else if(color[neigh] == color[node]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // already adj list is given so use this
        vector<int> visited(graph.size(), 0), color(graph.size(), -1);

        for(int i=0; i<graph.size(); i++){
            if(!visited[i]){
                visited[i] = 1; 
                color[i] =1;
                bool isBipertite = bfs(graph, i, visited, color);
                if(!isBipertite) return false;
            }
        }
        return true;
    }
};
