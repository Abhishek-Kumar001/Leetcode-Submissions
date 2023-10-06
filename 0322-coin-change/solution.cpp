class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // striver code

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
    
        for(int i=1; i<=amount; i++){
            if( i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }

        for(int i=1; i<n; i++){
            for(int amt =1; amt<= amount; amt++ ){
                 // take 
                 int take = INT_MAX;
                 if( amt >= coins[i]){
                     take = 1 + dp[i][amt - coins[i]];
                 }

                 //not take 
                 int notTake  = dp[i-1][amt];

                
                dp[i][amt] = min( take , notTake );
            }
        }

        int ans = dp[n-1][amount];
        if( ans >=  1e9 ) ans = -1; 
        return ans;
    }
};
