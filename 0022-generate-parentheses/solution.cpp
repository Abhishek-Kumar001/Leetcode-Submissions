class Solution {
    void helper(int open, int close, string temp, vector<string> &ans){
        if(open == 0 && close == 0){
            ans.push_back(temp);
            return;
        }

        if(open){
            temp += '(';
            helper(open-1, close, temp, ans);
            temp = temp.substr(0, temp.size()-1); // we can use temp.pop_back() also
        }
        if(close > open){
            temp += ')';
            helper(open, close-1, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";

        helper(n, n, temp, ans);
        return ans;
    }
};
