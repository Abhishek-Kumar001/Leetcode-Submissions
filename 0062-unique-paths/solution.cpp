// class Solution {

// public:
//     vector<vector<int>> dp;
//     int solve(int m, int n){
//         if(m == 0 && n == 0) return 1;
//         if(m < 0 || n < 0)  return 0;

//         if(dp[m][n] != -1) return dp[m][n];

//         int up = solve(m-1, n);
//         int left = solve(m, n-1);

//         return dp[m][n] = up + left;
//     }
//     int uniquePaths(int m, int n) {
//         dp.assign(m, vector<int>(n, -1));

//         return solve(m-1, n-1);
//     }
// };



// class Solution {

// public:
//     vector<vector<int>> dp;
//     int uniquePaths(int m, int n) {
//         dp.assign(m, vector<int>(n, 0));

//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(i == 0 || j == 0) dp[i][j] = 1;
//                 else{
//                     int up = dp[i-1][j];
//                     int left = dp[i][j-1];
                    
//                     dp[i][j] = up + left;
//                 }
//             }
//         }

//         return dp[m-1][n-1];
//     }
// };



class Solution {

public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
       vector<int> prev(n, 1), curr(n, 0);

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(j == 0) curr[j] = 1;
                else{                    
                    curr[j] = prev[j] + curr[j-1];
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }
};
