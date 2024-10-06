// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n=grid.size(), m=grid[0].size();

//         vector<int> prev(m,0);
//         prev[0] = grid[0][0];
//         for(int j=1; j<m; j++){
//             prev[j] = prev[j-1] + grid[0][j];
//         }
        
//         for(int i=1; i<n; i++){
//             vector<int> curr(m, 0);
//             for(int j=0;j<m; j++){
//                 if(j==0){
//                     curr[j] =  grid[i][j] + prev[j];
//                 }
//                 else{
//                     curr[j] =  grid[i][j] + min(curr[j-1] , prev[j]);
//                 }
//             }
//             prev = curr;
//         }
//         return prev[m-1];
//     }
// };




class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<int> prev(m, 1e8);
        
        for(int i=0; i<n; i++){
            vector<int> curr(m, 0);
            for(int j=0; j<m; j++){
                if(i==0  && j==0){
                    curr[0] = grid[0][0];
                   
                }else{
                    int left = 1e9;
                    if(j != 0) left = curr[j-1];
                    int up = 1e9;
                    if(i != 0) up = prev[j];

                    curr[j] = grid[i][j] + min(left, up); 
                }                
            }
            prev = curr;
        }

        return prev[m-1];
    }
};
