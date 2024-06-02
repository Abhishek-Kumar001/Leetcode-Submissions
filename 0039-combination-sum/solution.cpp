class Solution {
    void solve(int ind, vector<int> &candidates, vector<vector<int>> &ans,     int target, vector<int> temp)
    { 
        //base case - 1
        if(ind >= candidates.size()) return ;
        //base case - 2
        if(target == 0){
            ans.push_back(temp);
            return ;
        }
        //base case - 3
        if(target < candidates[ind]) return;

        
        // now we have to choices -> take or notTake 
        // Take
        temp.push_back(candidates[ind]);
        solve(ind, candidates, ans, target-candidates[ind], temp);
         //backtrack
        temp.pop_back();
        
        // notTake
        solve(ind+1, candidates, ans, target, temp);   

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, ans, target, temp);
        return ans;
    }
};
