class Solution {
public:

    void solve(vector<vector<int>> &ans, vector<int> temp, vector<int>& candidates, int require, int index ){
        if(require == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i<candidates.size(); i++){
            if(i >index &&  candidates[i] == candidates[i-1]){
                continue;
            }
            if(require >= candidates[i]){
                temp.push_back(candidates[i]);
                solve(ans, temp, candidates, require-candidates[i], i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        solve(ans, temp, candidates, target, 0);
        return ans;
    }
};
