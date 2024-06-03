class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int miniSize = INT_MAX;
        int sumSoFar = 0;
        int j=0;
        for( int i=0; i<nums.size(); i++){
            sumSoFar+=nums[i];

            while(sumSoFar >= target){                        
                miniSize= min(miniSize, i-j+1);  

                sumSoFar-=nums[j];
                j++;
            }
            
        }
        return miniSize == INT_MAX ? 0 : miniSize;
    }
};
