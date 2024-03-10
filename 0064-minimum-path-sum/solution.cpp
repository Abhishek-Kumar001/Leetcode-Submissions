class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m);
        prev[0] = grid[0][0];
        for(int i=1; i<m; i++){
            prev[i] = prev[i-1] + grid[0][i];
        }
        
        for(int i=1;i<n; i++){
            vector<int> curr(m);
            for(int j=0; j<m; j++){
                if(j==0) curr[j] = grid[i][0]+prev[0];
                else{
                    curr[j] = min( prev[j], curr[j-1]) + grid[i][j];
                }
            }
            prev = curr;
        }
        
       
        return prev[m-1];
    }
};
