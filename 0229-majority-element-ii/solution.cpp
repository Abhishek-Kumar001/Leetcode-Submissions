class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int reqTime = (nums.size()/3)+1;
        vector<int> ans;
        for(int it : nums){
            //vvvi to not take duplicates eg = [2,2] or eg=[2,2,2,2,2]
            if( ans.size()!=0 && ans.back() == it){
                continue;
            }
            mp[it]++;

            if(mp[it] >= reqTime){
                ans.push_back(it);
            }

            if(ans.size() == 2) return ans; // there can be at max 2 nos can be max no so 
            // if we have got 2 nos then return from here 
        }
        return ans;
    }
};
