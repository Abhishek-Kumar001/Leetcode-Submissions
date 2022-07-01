class Solution {
    public boolean isValid(String s) {
        
        //creating a stack
        Stack<Character> stk= new Stack();
        
        for(int i=0; i<s.length() ; i++){
            char ch=s.charAt(i);
                
                //if ch is opning brecket
            if(ch=='(' || ch=='{'  || ch=='['){
                 stk.push(ch);
            }
            
            //if ch is closing brackets
            else if(ch==')' || ch=='}' || ch==']'){
                 //if stack is full
                if(stk.isEmpty()){
                    return false;
                }
                else if(!stk.isEmpty()){
                    char top=stk.peek();
                    if( (ch==')'  && top=='(' )  ||
                         (ch=='}'  && top=='{')  ||
                         (ch==']'  && top=='[')  ){
                        stk.pop();
                    }
                    else{
                        return false;
                    }
                }    

            }
        }
        return stk.isEmpty();
                       
    }
}
