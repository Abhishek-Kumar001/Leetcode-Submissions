class Solution {
    int houseRob(int startInd, int n, vector<int> &nums){
        int size = nums.size();
        if(size == 1) return nums[0];

        vector<int> dp(size, 0);

        dp[startInd] = nums[startInd];
        if(startInd == n-1) return dp[startInd];
        dp[startInd+1] = max(nums[startInd], nums[startInd+1]);

        for(int i = startInd+2; i<n; i++){
            int take = nums[i] + dp[i-2];
            int notTake = 0 + dp[i-1];
            dp[i] = max(take, notTake);
        }

        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(houseRob(0, n-1, nums), houseRob(1, n, nums));
    }

};
