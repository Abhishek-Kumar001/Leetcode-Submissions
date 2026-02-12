// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
//         // bruit force 

//         for(int i=0; i<nums.size(); i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(abs(i-j) <= indexDiff){
//                     if(abs(nums[i] - nums[j]) <= valueDiff){
//                         return true;
//                     }
//                 }else break;
//             }
//         }
//         return false;
//     }
// };



class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        //handling the tle test case
        set<int> ss(nums.begin(), nums.end());
        if(valueDiff == 0 && n == ss.size()) return false;

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(abs(i-j) <= indexDiff){
                    if(abs(nums[i] - nums[j]) <= valueDiff){
                        return true;
                    }
                }else break;
            }
        }
        return false;
    }
};
