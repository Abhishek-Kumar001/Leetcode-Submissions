class Solution {
    void helper( int openBracket, int closeBracket, vector<string> &ans, string temp){
        // base case
        if(openBracket == 0 && closeBracket == 0){
            ans.push_back(temp);
            return;
        } 


        // 1st we will have to take '(' then only we can take ')'
        if(openBracket){
            openBracket--;
           temp += '(';
           helper(openBracket, closeBracket, ans, temp);
           temp.pop_back();
           openBracket++;
        }
        // now take closeBracket if and only if we have more number of closing bracket
        if(closeBracket > openBracket){
            temp+=')';
            closeBracket--;
            helper(openBracket, closeBracket,ans, temp);
        }
    }
public:
    vector<string> generateParenthesis(int n) { 
        vector<string> ans;
        helper(n, n, ans, "");
        return ans;
    }
};
