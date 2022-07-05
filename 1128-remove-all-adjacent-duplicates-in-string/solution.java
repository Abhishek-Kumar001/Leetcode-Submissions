class Solution {
    public String removeDuplicates(String s) {
      
        Stack<Character> stk=new Stack<>();
        
        for(int i=0; i<s.length(); i++){
            char ch=s.charAt(i);
            if(   ( !stk.isEmpty() )  &&  ch==stk.peek() ) {
                  stk.pop();
            }
            else {
                 stk.push(ch);
            }
        }
        
        String ans=new String();
        while( !stk.isEmpty() ){
            char ch=stk.pop();
             ans=ch+ans;
        }
        

        return ans;
    }
}
