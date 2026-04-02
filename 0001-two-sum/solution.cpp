class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;

        for(int i=0; i<nums.size(); i++){
            int req = target - nums[i];
            if(mpp.find(req) != mpp.end()){
                return {i, mpp[req]};
            }

            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }
};
