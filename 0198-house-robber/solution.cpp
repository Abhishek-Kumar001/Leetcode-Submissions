class Solution {
    vector<int> dp;
    int solve(int i, vector<int> &nums){
        if(i == 0 ) return nums[0];
        if(i < 0) return 0;
        
        if(dp[i] != -1) return dp[i];

        int take =  nums[i] + solve(i-2, nums);
       
        int notTake = solve(i-1, nums);

        return dp[i] = max(take, notTake); 
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        return solve(n-1, nums);
    }
};
