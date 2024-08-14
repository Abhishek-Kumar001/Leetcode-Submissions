class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        //handling the tle test case
        set<int> ss(nums.begin(), nums.end());
        if(valueDiff == 0 && n == ss.size()) return false;

        
        for(int i=0; i<n; i++){          
            for(int j=i+1; j<=i+indexDiff && j<n; j++ ){
                if(abs(nums[i] - nums[j])  <= valueDiff){
                    return true;
                }
            }        
        }
        return false;
    }
};
