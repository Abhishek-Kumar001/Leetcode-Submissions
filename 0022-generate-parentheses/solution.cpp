class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", n, n, ans);
        return ans;
        
    }
    void solve( string op, int open, int close, vector<string> &ans){
        //base case
        if( open ==0  && close == 0){
            ans.push_back( op );
            return ;
        }
        
        if( open != 0){
            string op1 = op + "(";
            solve( op1, open-1, close, ans);
        }
        if( close != open){
            string op2 = op + ")";
            solve( op2, open, close-1, ans);
        }
    }
};
