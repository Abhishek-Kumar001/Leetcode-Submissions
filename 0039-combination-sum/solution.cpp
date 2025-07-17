class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tempArr;
        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, ans, tempArr);
        return ans;
    }

    void solve(int ind, vector<int> arr, int req, vector<vector<int>> &ans, vector<int> tempArr){
        if(ind == arr.size()) return ;
        if(req == 0){
            ans.push_back(tempArr);
            return ;
        }
        // order is vvi , if i put it above i will get wrong ans
        if(req < arr[ind]) return ;

        // not take  first so that we don't need to do pop_back latter
        solve(ind+1, arr, req, ans, tempArr);
        //take 
        tempArr.push_back(arr[ind]);
        solve(ind, arr, req-arr[ind], ans, tempArr);
    }
};
