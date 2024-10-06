class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        priority_queue<pair<int, pair<int, int>>> maxpq;
        health = health - grid[0][0];  // vvi corner case 
        // grid[0][0] also can v unsafe
        maxpq.push({health, {0,0}});
        visited[0][0] = 1;


        int drow[] = {0, +1, 0, -1};
        int dcol[] = {+1, 0, -1, 0};

        while(!maxpq.empty()){
            int health = maxpq.top().first;
            int row = maxpq.top().second.first;
            int col = maxpq.top().second.second;

            maxpq.pop();

            if(row == n-1 && col == m-1) {
                return health >=1;
            }

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol<m && !visited[nrow][ncol] ){
                    visited[nrow][ncol] = 1;
                    int newHealth = health - grid[nrow][ncol];
                    maxpq.push({newHealth, {nrow, ncol}});
                }
            }
            
        }
        return false;
    }
};
