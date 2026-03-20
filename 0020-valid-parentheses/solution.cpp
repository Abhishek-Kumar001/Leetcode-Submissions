class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                stk.push(ch);
            }else{
                if(stk.size() == 0) return false;
                char top = stk.top();

                 if((top == '(' && ch == ')')  ||   (top == '{' && ch == '}')  || 
                   (top == '[' && ch == ']') 
                ) stk.pop();
                else return false;
            }
        }

        return stk.size() == 0;
    }
};
