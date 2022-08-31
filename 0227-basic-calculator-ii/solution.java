class Solution {
    public int calculate(String s) {
        
        //creating 2 stacks  one for storing operators and other for storing operands
        Stack<Integer> stkInt=new Stack<>();
        Stack<Character> stkOperator= new Stack<>();
        
        //now it is given that our string contains only integer, operators and spaces
        //so first remove all white spaces from the string
        s=s.replaceAll("\\s","");
        //not our string only contains integer and operators
        for(int i=0; i<s.length(); i++){
            char ch=s.charAt(i);
          
             if(ch == '+'  ||  ch == '-' ){
                 if(stkOperator.isEmpty() ){
                     stkOperator.push(ch);
                 }
                 else{
                    //pop two  ele form stkInt 
                    int data2=stkInt.pop();
        
                    int data1=stkInt.pop();
                 
                   //porform that operation and store the result back in to stkInt stack
                   int result=0;
                   char top= stkOperator.pop();
                   if(top == '-'){
                     result = data1 - data2;
                   }
                   else{
                     result = data1 + data2;
                   }                 
                   stkInt.push(result); 
                   //current operator ko stkOperator me push karna
                   stkOperator.push(ch);
                }   
             }
             else if(ch == '*'  || ch=='/'){
                 //pop one ele form stkInt
                 int data1=stkInt.pop();
                 //get next number not  integer of ( * or /) from the string
                 String temp=new String();
                  int j=i+1;
                  for( j=i+1 ; j<s.length() && ( s.charAt(j) >=48 && s.charAt(j)<=57 ) ;                                                                                       j++){
                      temp+=s.charAt(j);
                  }
                  i=j-1;   // VVI LINE 
                  int data2=0;
                  try{
                      data2=Integer.parseInt(temp);
                     
                  }
                  catch(NumberFormatException e){
                
                  }    
                 
                 //porform that operation and store the result back in to stkInt stack
                 int result=0;
                 if(ch == '*'){
                     result = data1 * data2;
                 }
                 else{
                     result = data1 / data2;
                 }                 
                 stkInt.push(result);
              }   
              else{  //definitely ch is digit(mark it is a digit not a no, we have to make is no )
               
                 /* int data=Character.getNumericValue(s.charAt(0));
                  stkInt.push(data);  
                  */
                  String temp=new String();
                  int j=0;
                  for( j=i; j<s.length() && ( s.charAt(j) >=48 && s.charAt(j)<=57 ) ;                                                                                       j++){
                      temp+=s.charAt(j);
                  }
                  i=j-1;   // VVI LINE 
                  try{
                     int val=Integer.parseInt(temp);
                     stkInt.push(val);
                  }
                  catch(NumberFormatException e){
                  }    
               }          
        }

        //now our operator  stack contains ONLY   + and -
        while(  !stkOperator.isEmpty() ){
            char ch=stkOperator.pop();
            //pop 2 elements form stkInt and porform operation and push result into stkInt 
            int d2 = stkInt.pop();
            int d1 = stkInt.pop();
            
            int res=0;
            if(ch=='-'){
                res= d1 - d2;
            }
            else{
                res = d1 + d2;
            }
            stkInt.push(res);
        }
        if(stkInt.size() == 1){
            return stkInt.pop();
        }
        return stkInt.pop();        
    }
}
