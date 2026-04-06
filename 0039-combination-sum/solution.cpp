class Solution {
    void helper(int i, vector<int> &candidates, int target, vector<int> temp, vector<vector<int>> & ans){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }

        if(i == candidates.size()) return ;
        if(candidates[i] > target) return ;


        // take 
        temp.push_back(candidates[i]);
        helper(i, candidates, target - candidates[i], temp, ans);
        temp.pop_back();
        
        // not take 
        helper(i+1, candidates, target, temp, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        helper(0, candidates, target, temp, ans);
        return ans;
    }
};
