class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> open;
        stack<char> close;
        for(char ch : s){
            if( ch == '(') open.push('(');
            else{
                if(open.size() == 0){
                    close.push(')');
                }else open.pop();
            }
        }
        return (open.size() + close.size());
    }
};
