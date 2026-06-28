class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubarraySum = nums[0];
        int tempSum = 0;
        for(int x : nums){
            tempSum += x;

            if(tempSum > maxSubarraySum){
                maxSubarraySum = tempSum;
            }

            if(tempSum <= 0) tempSum = 0;
        }
        return maxSubarraySum;
    }
};
