class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> result(n, vector<int>(m, 0));


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) result[0][0] = 1;
                else if(i == 0){
                    if(j > 0 && result[i][j-1] != 0 && obstacleGrid[i][j] != 1)
                       result[i][j] = 1;
                }else if(j == 0){
                    if(i > 0 && result[i-1][j] != 0 && obstacleGrid[i][j] != 1)
                       result[i][j] = 1;
                }else{
                    if(obstacleGrid[i][j] != 1)
                       result[i][j] = result[i-1][j] + result[i][j-1];
                }
            }
        }
        return result[n-1][m-1];
    }
};
