class Solution {
    void solve(int ind, vector<int> &nums, set<vector<int>> &ansSet){
        if(ind == nums.size()){
            ansSet.insert(nums);
            return;
        }
        
        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            solve(ind+1, nums, ansSet);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ansSet;
        solve(0, nums, ansSet);
        vector<vector<int>> ansVec;
        for( auto it: ansSet){
            ansVec.push_back(it);
        }
        return ansVec;
    }
};
