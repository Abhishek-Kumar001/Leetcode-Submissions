// // BRUIT FORCE - RECURSION
// class Solution {
// public:
//     int solve(int ind, int amount, vector<int> &coins){
//         // base case
//         if(amount == 0) return 1;
//         // base case 2
//         if(ind >= coins.size())  return 0;

//         // now we have 2 options i.e take and not take
//         int take = 0, notTake = 0;
//         if(coins[ind] <= amount){
//            take = solve(ind, amount-coins[ind], coins);
//         }
//         notTake = solve(ind+1, amount, coins );

//         return take + notTake;
//     }
//     int change(int amount, vector<int>& coins) {
//         return solve(0, amount, coins);
//     }
// };



// // OPTIMIZED - MEMOIZATION
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount + 1));
//         for (int i = 0; i < n; i++) {
//             dp[i][0] = 1;
//         }

//         // base case 2
//         for(int i=coins[0]; i<=amount; i++)
//             if(i % coins[0] == 0)
//                 dp[0][i] = 1;

//         for (int i = 1; i < n; i++) {
//             for (int req = 1; req <= amount; req++) {
//                 int take = 0;
//                 if (coins[i] <= req) {
//                     take = dp[i][req - coins[i]];
//                 }
//                 int notTake = dp[i-1][req];

//                 dp[i][req] = take + notTake;
//             }
//         }

//         return dp[n-1][amount];
//     }
// };

// in the above solution i was getting overflow: 2123074792 + 27131803 cannot be represented in type 'int' (solution.cpp)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        // Use unsigned int to prevent signed integer overflow
        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount + 1, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // base case 2
        for(int i = coins[0]; i <= amount; i++) {
            if(i % coins[0] == 0) {
                dp[0][i] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int req = 1; req <= amount; req++) {
                // Update temporary variables to unsigned int as well
                unsigned int take = 0;
                if (coins[i] <= req) {
                    take = dp[i][req - coins[i]];
                }
                unsigned int notTake = dp[i-1][req];

                dp[i][req] = take + notTake;
            }
        }

        return dp[n-1][amount];
    }
};
