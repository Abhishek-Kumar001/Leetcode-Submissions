class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int val : nums) sum+=val;
        if(sum % 2 == 1) return false;

        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));

        for(int i=0; i<n; i++) dp[i][0] = 1;
        if(nums[0] <= target) dp[0][nums[0]] = 1;
        
        for(int i=1; i<n; i++){
            for(int tar = 1; tar<=target; tar++){
                int take = 0;
                if(nums[i] <= tar ) take = dp[i-1][tar-nums[i]];
                int notTake = dp[i-1][tar];

                dp[i][tar] = take || notTake;
            }
        }
        return dp[n-1][target];
    }
};
