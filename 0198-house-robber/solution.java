// Method 1 : Recursion
// class Solution {
//     public int rob(int[] nums) {
//         // method 1 : recursion
//         return  helper(nums, nums.length-1, nums.length);
//     }

//     public int helper(int[] nums, int i, int n){
//         // base case 
//         if(i < 0) return 0;
//         if(i == 0) return nums[0];

//         //now we have 2 case : take and not take 
//         int take = nums[i] + helper(nums, i-2, n);
//         // int case:2 not take 
//         int notTake = 0 + helper(nums, i-1, n);

//         return Math.max(take, notTake);
//     }
// }



// Method 2 : Memoization 
// class Solution {
//     public int rob(int[] nums) {
//         // method 2: Memoization
//         int n = nums.length;
//         int dp[] = new int[n];
//         for(int i=0; i<n; i++) dp[i] = -1;

//         return  helper(nums, n-1, n, dp);
//     }

//     public int helper(int[] nums, int i, int n, int []dp){
//         // base case 
//         if(i < 0) return 0;
//         if(i == 0) return nums[0];

//         if(dp[i] != -1) return dp[i];

//         //now we have 2 case : take and not take 
//         int take = nums[i] + helper(nums, i-2, n, dp);
//         // int case:2 not take 
//         int notTake = 0 + helper(nums, i-1, n, dp);

//         return dp[i] = Math.max(take, notTake);
//     }
// }


// // Method 3 : tabulation 
// class Solution {
//     public int rob(int[] nums) {
//         // method 2: Memoization
//         int n = nums.length;
//         int dp[] = new int[n];

//         for(int i=0; i<n; i++){
//             //now we have 2 case : take and not take 
//             int take  = nums[i];
//             if(i > 1)
//               take += dp[i-2];
//             // int case:2 not take 
//             int notTake = 0;
//             if(i > 0)
//               notTake += dp[i-1];

//             dp[i] = Math.max(take, notTake);
//         }

//         return  dp[n-1];
//     }
// }


// Method 4 : Space Optimization 
class Solution {
    public int rob(int[] nums) {
        // method 4: Space Optimization
        int n = nums.length;
        int prevPrev = nums[0];
        if(n == 1) return nums[0];
        int prev = Math.max(nums[0], nums[1]);

        for(int i=0; i<n; i++){
            //now we have 2 case : take and not take 
            int take  = nums[i];
            if(i > 1)
              take += prevPrev;
            // int case:2 not take 
            int notTake = 0;
            if(i > 0)
              notTake += prev;

            prevPrev = prev;
            prev = Math.max(take, notTake);
        }

        return  prev;
    }
}
