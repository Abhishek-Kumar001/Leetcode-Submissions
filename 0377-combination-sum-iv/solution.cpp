/*
class Solution {
    public:
    int solve( vector<int> &nums, int target, int n, vector<int> &dp){

        if(dp[target] != -1) return dp[target];

        int take =0;
        for(int i=0; i<n; i++){
            if( nums[i] <= target){
                take += solve( nums, target - nums[i], n, dp);
            }
        }
        dp[target] = take ;
        return  take;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        // code with alisha appproah
        int n  = nums.size();
        vector<int> dp(target+1, -1);
        dp[0] = 1;

        return  solve( nums, target,n,dp);
    }
};
*/


class Solution {
    public:
    int solve( vector<int> &nums, int ind,  int target, int n,vector<vector<int>> &dp ){
         // base case
         if( target == 0){
             return 1;
         }

         if( ind >= n){
             return 0;
         }
         
         if( dp[ind][target] != -1) return dp[ind][target];

         int take = 0;
         if( nums[ind] <= target){
             take = solve(nums, 0, target-nums[ind], n, dp);
         }
         int notTake = solve(nums, ind+1, target, n, dp);

         return dp[ind][target] = take + notTake;
        
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        // code with alisha appproah
        int n  = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return  solve( nums,0, target,n,dp);
    }
};
