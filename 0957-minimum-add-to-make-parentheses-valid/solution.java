class Solution {
    public int minAddToMakeValid(String s) {
        int cnt = 0;
        Stack<Character> stk = new Stack<Character>();
        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            if(ch == ')' ){
                if(stk.size() >= 1){
                    stk.pop();
                }else{
                    cnt++;
                }
            }
            else{  // definitly it is '('
                stk.push(ch);
            }
        }
        cnt += stk.size();
        return cnt;
    }
}
