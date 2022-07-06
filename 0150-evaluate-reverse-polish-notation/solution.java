class Solution {
    public int evalRPN(String[] s) {
       //create an stack to store integers
        Stack<Integer> stk=new Stack<>();
        int result=0;
        for(String s1: s){
            // if string is opetators then pop()  2 values and performs num2 operator num1
          
            if(s1.equals("+") ||  s1.equals("-") ||  s1.equals("*") ||  s1.equals("/")  ){
                //to pop 2 elements and perform operration if of all stack me 2 elements toh hona                 //chihita na
                if(stk.size() >=2){
                    int num1=stk.pop();
                    int num2=stk.pop();
                    
                    if(s1.equals("+") )
                      result=num2 + num1;
                    
                    if(s1.equals("-") )
                      result=num2 - num1;
                    
                    if(s1.equals("*") )
                      result=num2 * num1;
                    
                    if(s1.equals("/") )
                      result=num2 / num1;

                    stk.push(result);
                }
            }
            else{
               try{
                  int val=Integer.parseInt(s1);
                  stk.push(val);
               }
               catch(NumberFormatException e){
                
               }
           }
        }
        return stk.peek();
    }
}
