class Solution {
public:
    int rob(vector<int>& nums) {
        if( nums.size() == 1) return nums[0];
        
        vector<int> nums1, nums2;
        for( int i=0; i<nums.size(); i++){
            if( i != nums.size()-1) nums1.push_back( nums[i]);
            if( i != 0) nums2.push_back( nums[i]);       
        }
        return max( solve(nums1), solve(nums2));
    }
    int solve( vector<int> nums){
        int prev1= nums[0];
        if( nums.size() == 1) return nums[0];
        int prev2 = max(nums[0], nums[1]);
        
        for( int i=2;i<nums.size(); i++){
            int curr = max( prev2,  nums[i]+ prev1);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};
