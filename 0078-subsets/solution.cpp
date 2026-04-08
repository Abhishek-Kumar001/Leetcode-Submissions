class Solution {
    void helper(int ind, vector<int> &nums, vector<int> temp, vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }
        if(ind > nums.size()) return ;

        // now we have 2 choices 
        // 1st take 
        temp.push_back(nums[ind]);
        helper(ind+1, nums, temp, ans);
        temp.pop_back();

        // 2nd - not take
        helper(ind+1, nums, temp, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        helper(0, nums, temp, ans);
        return ans;
    }
};
