class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int tempSum = 0;
        int minLength = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            tempSum +=nums[i];

            if(tempSum == target){
                minLength = min(minLength, i-s+1);
            }

            while(tempSum >= target){
                minLength = min(minLength, i-s+1);
                tempSum -= nums[s];
                s++;
            }
        }
        if(minLength == INT_MAX) return 0;
        return minLength;
    }
};
