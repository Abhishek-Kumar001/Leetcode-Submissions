class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum = 0;
        int start = 0;
        int minLength = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            sum+= nums[i];
            if(sum >= target){
                while(sum >=target){
                    minLength = min(minLength, i - start +1);
                    sum-=nums[start];
                    start++;
                }
            }
        }
        if(minLength == INT_MAX) return 0;
        return minLength;
    }
};
