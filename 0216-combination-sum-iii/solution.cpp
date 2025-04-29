class Solution {
    void helper(int k, int no, int require, vector<int> temp, vector<vector<int>> &ans){
        // base case
        if( require == 0  && k==0){
            ans.push_back(temp);
            return;
        }
        //base case
        if(k == 0) return;
        // base case 2
        if( no > 9) return;

        if(no > require) return;

        // take case 
        temp.push_back(no);
        helper(k-1, no+1, require-no, temp, ans);
        temp.pop_back();

        // not take 
        helper(k, no+1, require, temp, ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(k, 1, n, temp, ans);
        return ans;
    }
};
