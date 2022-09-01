class Solution {
    public String decodeString(String s) {
         //create two stack 1 for storing integers   and 2nd for storing string([,], and characters)
        Stack<Integer> intStk = new  Stack();
        Stack<String>  stringStk = new Stack();
        
        for(int i=0; i<s.length(); i++){
            char ch=s.charAt(i);
            
            if( ch>=48  && ch<=57){
                 //it is prefix and it canbe no  so find the no
                int res=0,k=0;
                for( k=i; ch>=48 && ch<=57 ; ){
                    res= res*10 + Character.getNumericValue(ch);
                    k++;
                    ch=s.charAt(k);
                }
                   
                intStk.push(res);
                i=k-1;
             } 
             else if(ch  == ']'){
                //pop stringStk till we don't  get "[" 
                 String tempAns= new String();
                 while( !stringStk.isEmpty()  &&  !(stringStk.peek()).equals("[") ){    //.equals()  vvi
                     tempAns=stringStk.pop() + tempAns;
                 }
                 if( !stringStk.isEmpty()){
                     stringStk.pop();    //removing "[" from the stringStk
                 }
                     
                 //here we have get the complete characters in a  [xyz...], so now multiply this string                      with  prefix  integer
                 
                  String ans= new String();  //vvi
                  for(int j=0;  ! intStk.isEmpty() &&  j<intStk.peek(); j++){
                      ans= tempAns+ans;
                  }
                  if( ! intStk.isEmpty() ){
                      intStk.pop();  // removing the prefix integer b/c we have done its working
                  }
                 //after multiplying with prefix integer put this tempAns string into  stringStk 
                 stringStk.push(ans);
                    
             }
             else{   // definitely it is either [ or a character
                 stringStk.push(""+ch);
             }
        }
        //here our stringStk contains ans of each blocks[]  so now is time to combine all ans
        String result= new String();
        while( !stringStk.isEmpty() ){
            result=stringStk.pop() + result;
        }
        return result;

    }
}
