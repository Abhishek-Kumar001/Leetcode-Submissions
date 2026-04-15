class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        for(int i=0; i<nums.size(); i++){
            if(mpp[nums[i]] == 0) mpp[nums[i]] = i+1;
            else if( abs(i - mpp[nums[i]])+1 <= k) return true;
            else mpp[nums[i]] = i+1;
        }
        return false;
    }
};
