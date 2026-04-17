class Solution {
    int helper(int ind, vector<int> &coins, int require, vector<vector<int>> &dp){
        if(ind == coins.size()) return 1e8;
        if(require == 0) return 0;

        if(coins[ind] > require) return 1e8;

        if(dp[ind][require] != -1) return dp[ind][require];


        int result = 1 + helper(ind, coins, require-coins[ind], dp);
        int result2 = 0 + helper(ind+1, coins, require, dp);
        return dp[ind][require] = min(result, result2);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int result =  helper(0, coins, amount, dp);;
        if(result == 1e8) return -1;
        return result;
    }
};
