class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>  result(n, vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0){
                   if(j > 0) result[i][j] = result[i][j-1] + grid[i][j];
                   else result[i][j] = grid[i][j];
                }else if(j == 0){
                   if(i > 0) result[i][j] = result[i-1][j] + grid[i][j];
                   else result[i][j] = grid[i][j];
                }else{
                    result[i][j] = grid[i][j] + min(result[i-1][j], result[i][j-1]);
                }
            }
        }
        return result[n-1][m-1];
    }
};
