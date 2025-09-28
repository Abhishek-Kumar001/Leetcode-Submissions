class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int first = 0;
        int second = 1;
        int ans = 0;

        for(int i=2; i<nums.size(); i++){
            if(nums[first] + nums[second] > nums[i]) 
               ans =  (nums[first] + nums[second] + nums[i]);
               
            first = i-1;
            second = i;
        }
        return ans;
    }
};
