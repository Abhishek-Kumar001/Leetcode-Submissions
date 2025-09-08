     // Bruit Force - recursive way

// class Solution {
//     int helper(int ind, vector<int> nums){
//         // base case
//         if(ind >= nums.size()) return 0;

//         // choice 1 - take it 
//         int take = nums[ind] + helper(ind+2, nums);

//         //choice 2 - not take it
//         int notTake =  0 + helper(ind+1, nums);

//         return max(take, notTake);
//     }
// public:
//     int rob(vector<int>& nums) {
//         return helper(0, nums);
//     }
// };








//             // memoization
// class Solution {
//     int helper(int ind, vector<int> nums, vector<int> &dp){
//         // base case
//         if(ind >= nums.size()) return 0;

//         // memoize it
//         if(dp[ind] != -1) return dp[ind];

//         // choice 1 - take it 
//         int take = nums[ind] + helper(ind+2, nums, dp);

//         //choice 2 - not take it
//         int notTake =  0 + helper(ind+1, nums, dp);
 
//         return dp[ind] =  max(take, notTake);
//     }
// public:
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(), -1);
//         return helper(0, nums, dp);
//     }
// };




          // tabulation
class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            int take = INT_MIN;
            if( i > 1) take = nums[i] + dp[i-2];

            int notTake = INT_MIN;
            if( i > 0) notTake = max(dp[i-1], nums[i]);

            dp[i] = max(take, notTake);
        }
        // int maxi = dp[0];
        // for(int i=0; i<dp.size(); i++) maxi = max(maxi, dp[i]);
        // return maxi;

        return dp[nums.size()-1];
    }
};




//        // space optimization
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         // base case -- vvi
//         if(nums.size() == 1) return nums[0];

//         int prev1 = nums[0];
//         int prev2 = max(nums[0], nums[1]);

//         for(int i=2; i<nums.size(); i++){
//             int take = nums[i] + prev1;
//             int notTake = prev2;

//             prev1 = prev2;
//             prev2 = max(take, notTake);
//         }

//         return prev2;
//     }
// };
