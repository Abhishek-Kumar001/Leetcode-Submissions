class Solution {
    void helperFun(int i, int target, vector<int> candidates, vector<int> temp, vector<vector<int>> &ans){
        // base case
        if(i >= candidates.size()) return ;
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        // if(candidates[i] > target) return ;


        // take 
        if( candidates[i] <= target){
            temp.push_back(candidates[i]);
            helperFun(i, target-candidates[i], candidates, temp, ans);
            temp.pop_back();
        }

        // not take 
        helperFun(i+1, target, candidates, temp, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        helperFun(0, target, candidates, temp, ans);
        return ans;
    }
};
