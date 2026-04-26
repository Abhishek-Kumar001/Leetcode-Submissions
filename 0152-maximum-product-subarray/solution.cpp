class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftMax = 1, rightMax = 1;
        int resultMax = nums[0];
        int n = nums.size();

        for(int i=0; i<n; i++){
            leftMax*=nums[i];
            rightMax*=nums[n-1-i];

            resultMax = max(resultMax, max(leftMax, rightMax));

            if(leftMax == 0) leftMax = 1;
            if(rightMax == 0) rightMax = 1; 
        }
        return resultMax;
    }
};
