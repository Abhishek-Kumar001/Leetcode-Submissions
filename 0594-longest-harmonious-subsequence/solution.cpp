// class Solution {
// public:
//     int findLHS(vector<int>& nums) {
//         int res = 0, left = 0, right = 1, curIndex = 0;
//         sort(nums.begin(), nums.end());
//         while (right < nums.size()) {
//             if (nums[right] - nums[left] == 1) {
//                 res = max(res, right - left + 1);
//             }
//             while(nums[right] - nums[left] > 1){
//                 ++left;
//             }
//             ++right;
//         }
//         return res;
//     }
// };





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
