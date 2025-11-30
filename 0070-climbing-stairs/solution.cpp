class Solution {
    int helper(int n, vector<int> &dp){
        if(n <= 0 ) return 0;
        if(n == 1 || n == 2){
            dp[n] = n;   // vvi if we are returning dp[n] not returning what helper return
            return n;
        } 

        if(dp[n] != -1) return dp[n];

        int oneStep = helper(n-1, dp);
        int twoStep = helper(n-2, dp);

        return dp[n] = oneStep + twoStep;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        helper(n, dp);
        return dp[n];   
    }
};
