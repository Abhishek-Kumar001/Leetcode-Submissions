// class Solution {
//     int helper(int n, vector<int> &dp){
//         // base case 
//         if(n < 0) return 0;
//         if(n == 0) return 1;

//         if(dp[n] != -1) return dp[n];

//         int oneStair = helper(n-1, dp);
//         int twoStair = helper(n-2, dp);
//         return dp[n] = oneStair + twoStair;
//     }
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1, -1);
//         return helper(n, dp);
//     }
// };


class Solution {
   
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
             int oneStair = dp[i-1];
             int twoStair = dp[i-2];
             dp[i] = oneStair + twoStair;
        }

        return dp[n];
    }
};
