class Solution {
public:
    int helper(vector<int>& nums) {
        // my code space optmization
        int n = nums.size();
        if( n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            dp[i] = max( dp[i-1] , nums[i]+dp[i-2]);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        // only a little change in House Robber -1    

        int n = nums.size();
        // corner case
        if( n == 1) return nums[0];

        vector<int> nums1(n-1);
        vector<int> nums2(n-1);

        for(int i=0; i<n; i++){
            if( i != 0){
                nums1.push_back( nums[i] );
            }
            if( i != n-1){
                nums2.push_back( nums[i] );
            }
        }
        return max( helper(nums1), helper(nums2));
    }
};
