class Solution {
private:
    void helper(int ind, int n,vector<int> nums, vector<int> temp, vector<vector<int>> &ans){
        //base case 
        if(ind == n){
            ans.push_back(temp);
            return;
        } 

        //take 
        temp.push_back(nums[ind]);
        helper(ind+1, n, nums, temp, ans);
        //notTake 
        temp.pop_back();
        helper(ind+1, n, nums, temp, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp ;
        helper(0, nums.size(), nums, temp, ans);
        return ans;
    }
};
