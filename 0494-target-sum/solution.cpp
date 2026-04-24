class Solution {
public:
    int solve(vector<int> & nums, int target){
        vector<int> prev(target+1, 0);
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;

        if(nums[0] != 0 && nums[0] <= target) prev[nums[0]] = 1;


        for(int i=1; i<nums.size(); i++){
            vector<int> curr(target+1, 0);
            for(int t = 0; t<=target; t++){
               int notTake = prev[t];
               int take = 0;
               if(nums[i] <= t)
               take = prev[t - nums[i]];

               curr[t] = take + notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int x : nums) sum+=x;

        if(sum - target < 0 || (sum - target)%2 ) return 0;

        return solve(nums, (sum-target) / 2);
    }
};
