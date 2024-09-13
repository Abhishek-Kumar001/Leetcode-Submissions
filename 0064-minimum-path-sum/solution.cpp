class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<int> prev(m,0);
        prev[0] = grid[0][0];
        for(int j=1; j<m; j++){
            prev[j] = prev[j-1] + grid[0][j];
        }
        
        for(int i=1; i<n; i++){
            vector<int> curr(m, 0);
            for(int j=0;j<m; j++){
                if(j==0){
                    curr[j] =  grid[i][j] + prev[j];
                }
                else{
                    curr[j] =  grid[i][j] + min(curr[j-1] , prev[j]);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};
