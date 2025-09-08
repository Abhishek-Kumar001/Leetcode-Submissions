//            // bruit force - recursion - may be TLE

// class Solution {
//     int helper(int n){
//         if(n == 0) return 1;
//         if(n < 0) return 0;

//         // move 1 staier
//         int oneStair = helper(n-1);
//         // move 2 stairs 
//         int twoStair = helper(n-2);

//         return oneStair + twoStair; 
//     }
// public:
//     int climbStairs(int n) {
//         if(n == 1) return 1;

//         return helper(n);
//     }
// };








//            // MEMOIZE

// class Solution {
//     int helper(int n, vector<int> &dp){
//         if(n == 0) return 1;
//         if(n < 0) return 0;

//         // memoize 
//         if(dp[n] != -1) return dp[n];

//         // move 1 staier
//         int oneStair = helper(n-1, dp);
//         // move 2 stairs 
//         int twoStair = helper(n-2, dp);

//         return oneStair + twoStair; 
//     }
// public:
//     int climbStairs(int n) {
//         if(n == 1) return 1;
 
//         vector<int> dp(n+1, -1);
//         return helper(n, dp);
//     }
// };








//         // TABULATION
// class Solution {

// public:
//     int climbStairs(int n) {
//         if(n == 1) return 1;
 
//         vector<int> dp(n, -1);
//         dp[0] = 1;
//         dp[1] = 2;

//         for(int i=2; i<n; i++){
//             int oneStair = dp[i-1];
//             int twoStair = dp[i-2];

//             dp[i] = oneStair + twoStair;
//         }
//         return dp[n-1];
//     }
// };






        // SPACE OPTIMIZATION
class Solution {

public:
    int climbStairs(int n) {
        if(n == 1) return 1;
 
        int prevStair = 2;
        int prevPrevStair = 1;

        for(int i=2; i<n; i++){
            int oneStair = prevStair;
            int twoStair = prevPrevStair;

            prevPrevStair = prevStair;
            prevStair = oneStair + twoStair;
        }
        return prevStair;
    }
};
