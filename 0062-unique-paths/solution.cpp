//               // RECURSION
// class Solution {
//     int helper(int r, int c, int m, int n){
//         // base case 
//         if(r == m-1  && c == n-1) return 1;

//         if(r >=m || c>=n) return 0;

//         // if valid go down
//         int down = helper(r+1, c, m, n);

//         // if valid go right
//         int right = helper(r, c+1, m, n);

//         return down + right;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         return helper(0, 0, m, n);
//     }
// };




              // MEMOIZATION
class Solution {
    int helper(int r, int c, int m, int n, vector<vector<int>> &dp){
        // base case 
        if(r == m-1  && c == n-1) return 1;

        if(r >=m || c>=n) return 0;

        // MOMOIZE IT
        if(dp[r][c] != -1) return dp[r][c];


        // if valid go down
        int down = helper(r+1, c, m, n, dp);

        // if valid go right
        int right = helper(r, c+1, m, n, dp);

        return dp[r][c] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, m, n, dp);
    }
};
