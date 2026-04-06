class Solution {
    void helper(int ind, vector<int> &candidates, int target, vector<int> temp, vector<vector<int>> & ans){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }

        if(ind == candidates.size()) return ;
        if(candidates[ind] > target) return ;

        
        for(int i = ind; i<candidates.size(); i++){
            if(i == ind || candidates[i] != candidates[i-1]){
                temp.push_back(candidates[i]);
                helper(i+1, candidates, target - candidates[i], temp, ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        helper(0, candidates, target, temp, ans);
        return ans;
    }
};
