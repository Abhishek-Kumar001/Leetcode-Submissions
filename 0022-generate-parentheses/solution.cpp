class Solution {
    void solve(int open, int close, string temp, vector<string> &ans){
        //base case 
        if(open == 0 && close == 0){
            ans.push_back(temp);
            return;
        }

        if(open){
            temp.push_back('(');
            solve(open-1, close, temp, ans);
            temp.pop_back();
        }
        if(close > open){
            temp.push_back(')');
            solve(open, close-1, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp= "";

        solve(n, n, temp, ans);
        return ans;
    }
};
