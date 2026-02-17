class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start =0, maxLen = 0;
        for(int end=1; end<nums.size(); end++){
            if( (nums[end] - nums[start]) == 1){
               
                  maxLen = max(maxLen, end-start+1);
            }

            while(nums[end] - nums[start] > 1){
                ++start;
            }
        }
        return maxLen;
    }
};

