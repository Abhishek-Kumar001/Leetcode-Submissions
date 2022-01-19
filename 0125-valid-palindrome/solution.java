class Solution {
    public boolean isPalindrome(String s) {
        s=s.toLowerCase();
      //  s=s.replaceAll("[^a-zA-Z0-9]","");
     //   if((s.isEmpty()))     return true;
    /*   for(int i=0;i<s.length();i++){
           char ch=s.charAt(i);
           if((ch<65 && ch>90)  ||  (ch<97 && ch>122) || (ch<48 && ch>57)){
               s=s.replace(ch,' ');
           }
        }    */

         s=s.replaceAll("[^a-zA-Z0-9]","");
              
          
    for(int i=0;i<s.length()/2;i++){
        int start=i;
        int end=s.length()-1-i;
        if(!(s.charAt(start)==s.charAt(end)))
            return false;
    }
           return true;
        
        
        
        
          /* String temp="";
              for(int i=s.length()-1;i>=0;i--){
                  temp=temp+s.charAt(i);
              }    
              if(temp.equals(s)){
                  return true;
              }
              else{
                  return false;
              }
             */
        
    }
}
