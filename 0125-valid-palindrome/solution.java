/*
// method - 1 ( best of best)
class Solution {
    public boolean isPalindrome(String s) {

         s=s.replaceAll("[^a-zA-Z0-9]","");
              
          
    for(int i=0;i<s.length()/2;i++){
        int start=i;
        int end=s.length()-1-i;
        if(!(s.charAt(start)==s.charAt(end)))
            return false;
    }
           return true;
        
        
    
        
    }
}
*/


//method 2 ( better)
class Solution{
   public boolean isPalindrome(String s) {
      
        String onlyChar = "" ;
        for(int i=0; i<s.length(); i++){
            if(  (s.charAt(i) >= 65 && s.charAt(i)<= 90 ) ||  ( s.charAt(i) >= 97 && s.charAt(i) <=122)   || 
                  ( s.charAt(i) >=48  && s.charAt(i) <=57 )){
                onlyChar += s.charAt(i);
            }
        }
         
       onlyChar = onlyChar.toLowerCase(); 
      // System.out.println(onlyChar);
       
       
        for(int i=0;i<onlyChar.length()/2;i++){
           int start=i;
           int end=onlyChar.length()-1-i;
           if((onlyChar.charAt(start)!= onlyChar.charAt(end)))
              return false;
           }
        return true;
       
    }
}
