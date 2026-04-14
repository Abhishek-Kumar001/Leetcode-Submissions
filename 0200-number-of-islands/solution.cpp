class Solution {
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited, int n, int m){
        visited[row][col] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && visited[nrow][ncol] == 0){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, false));

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    cnt++;
                    dfs(i, j, grid, visited, n, m);
                }
            }
        }
        return cnt;
    }
};
