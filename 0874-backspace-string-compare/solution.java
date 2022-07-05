class Solution {
    public boolean backspaceCompare(String s, String t) {
        
        Stack<Character> stk1=new Stack<>();
        Stack<Character> stk2=new Stack<>();
        
        //pushing charecters of string s in stack 1 if the charecter is # then pop one element 
        for(int i=0; i<s.length(); i++){
            char ch=s.charAt(i);
           
            if(ch != '#'){
                stk1.push(ch);
            } 
            else if(ch=='#' && ( !stk1.isEmpty() ) ){
                 stk1.pop();  
            }
        }
               
        //pushing charecters of string t in stack 2 if the charecter is # then pop one element 
        for(int i=0; i<t.length(); i++){
            char ch=t.charAt(i);
           
            if(ch != '#'){
                stk2.push(ch);
            } 
            else if(ch=='#' && ( !stk2.isEmpty() ) ){
                 stk2.pop();  
            } 
        } 
        
        while( ( !stk1.isEmpty() )  &&  ( !stk2.isEmpty() )  ){
            if(stk1.pop() != stk2.pop())
                return false;
        } 
        if(stk1.isEmpty()  &&  stk2.isEmpty()  ){
              return true;
        }             
         return false;                
    }
}
