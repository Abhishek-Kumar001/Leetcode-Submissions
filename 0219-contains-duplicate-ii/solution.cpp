class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>mpp;
        for(int i=0; i<nums.size(); i++){
            // if(mpp.find(nums[i]) != mpp.end()){
            //     int index=mpp[nums[i]];
            //     int dif=abs(index-i);
            //     if(dif <= k)
            //     return true;
            // }

            if(mpp.count(nums[i])){
                int index=mpp[nums[i]];
                int dif=abs(index-i);
                if(dif <= k)
                return true;
            }
            mpp[nums[i]]=i;
        }
        return false;
    }
};
