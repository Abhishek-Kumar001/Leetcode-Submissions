class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(string x : tokens){
            if(x == "+" || x == "-" || x == "*" || x == "/"){
                int top = stk.top();
                int second = top;
                stk.pop();
                top = stk.top();
                int first = top;
                stk.pop();

                int result = 0;
                if(x == "+") result = first + second;
                if(x == "-") result = first - second;
                if(x == "*") result = first * second;
                if(x == "/") result = first / second;

                stk.push(result);
            }else{
                int no = stoi(x);
                stk.push(no);
            }
        }
        int top = stk.top();
        return top;
    }
};
