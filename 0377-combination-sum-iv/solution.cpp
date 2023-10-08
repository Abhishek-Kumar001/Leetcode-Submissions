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
