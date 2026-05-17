class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN, tempSum=0;

        for(int x : nums){
            tempSum += x;
            sum = max(tempSum, sum);

            if(tempSum < 0) tempSum = 0;
        }
        return sum;
    }
};
