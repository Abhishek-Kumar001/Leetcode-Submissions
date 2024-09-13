class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) dp[0][0] = 1;
                else if(i==0 && obstacleGrid[0][j] == 0){
                    dp[0][j] = dp[0][j-1];
                }else if(j==0 && obstacleGrid[i][j] == 0){
                    dp[i][0] = dp[i-1][0];
                }else if(i != 0 && j!= 0){
                    if(obstacleGrid[i][j] == 0)
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
