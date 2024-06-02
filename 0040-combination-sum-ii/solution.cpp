class Solution {
    void solve(int ind, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> temp)
    {
        //base case 
        if( target == 0){
            ans.push_back(temp);
            return ;
        }

        

        for( int i=ind; i<candidates.size(); i++){
            if(i != ind && candidates[i]== candidates[i-1]){
                continue;
            }

            if(target < candidates[i] ) return ;

            temp.push_back(candidates[i]);
            solve(i+1, candidates, target-candidates[i], ans, temp);
            //backtrack
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, ans, temp);
        return ans;
    }
};
