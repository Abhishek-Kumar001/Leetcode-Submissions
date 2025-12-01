class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);

        for(int i=0; i<m; i++){
            vector<int> curr(n,0);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) curr[0] = grid[0][0];
                else if( i == 0 ) curr[j] = grid[i][j] + curr[j-1];
                else if( j == 0 ) curr[j] = grid[i][j] + prev[j];
                else curr[j] = grid[i][j] + min(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
