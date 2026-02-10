class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mpp;

        for(int i=0; i<nums.size(); i++){
            // if(mpp[nums[i]]){  
                // don't use this becuase if it not found then it initialized with 0
                // it means that number is not present i.e for eg1, 1 is not present as 1 is inserted as 0
        
            if (mpp.find(nums[i]) != mpp.end()) {
                int diff = abs(i - mpp[nums[i]]);
                if(diff <= k) return true;
            }
            mpp[nums[i]] = i;
        }
        return false;
    }
};
