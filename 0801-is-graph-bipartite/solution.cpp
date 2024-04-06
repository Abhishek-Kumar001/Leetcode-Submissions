class Solution {
private:
    bool check(int node, vector<int> &color,vector<vector<int>>& adjList, vector<int> &visited){
        color[node] = 1;
        visited[node] = 1;
        queue<int> q;
        q.push(node);

        while( !q.empty()){
            int front = q.front();
            q.pop();

            for( int neigh : adjList[front]){
                if(  visited[neigh] == 1  &&  color[neigh] == color[front]){
                    return false;
                }
                else if( visited[neigh] == 0 ) {
                    visited[neigh] = 1;
                    color[neigh] = !color[front];
                    q.push( neigh);
                }
            }
        }
        return true;
}
public:
    bool isBipartite(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> color(n, -1);
        vector<int> visited(n, 0);
        for( int i=0; i<n; i++){
            if( color[i] == -1){
                if( check( i, color, edges, visited )  == false ){
                    return false;
                }
            }	
        }
        return true;
    }
};
