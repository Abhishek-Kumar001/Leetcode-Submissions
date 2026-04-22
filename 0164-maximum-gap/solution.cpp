class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxGap = 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            maxGap = max(maxGap, nums[i]-nums[i-1]);
        }
        return maxGap;
    }
};
