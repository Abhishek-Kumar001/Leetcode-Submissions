class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
                //@ striver approach
    
        //since we have to find all nos which appears more than n/3 
        // and algically there can be at max 2 such nos present at max

        unordered_map<int,int> mp;
        int reqTime = (nums.size()/3)+1;
        vector<int> ans;
        for(int it : nums){
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
