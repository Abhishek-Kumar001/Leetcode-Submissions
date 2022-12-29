
class Solution {
    public String countAndSay(int n) {
       return solve(n);
    }
    public String solve(int n){
        //bace case
        if(n==1)  return "1";
        if(n==2)  return "11";
        if(n==3) return "21";

        String ans = solve(n-1);

        int count =1;
        String tempAns = new String("");
        for(int i=1; i<ans.length(); i++){
            if( i != ans.length() - 1){ 
                if(ans.charAt(i) != ans.charAt(i-1) ){
                  tempAns = tempAns + String.valueOf(count) + String.valueOf(ans.charAt(i-1) );
                  count=1;
                }
                else{
                  count++;
                }
            }    
            else{     // if it the last index
                if(ans.charAt(i) != ans.charAt(i-1) ){
                    tempAns = tempAns + String.valueOf(count) + String.valueOf(ans.charAt(i-1) );
                    
                    tempAns = tempAns + "1" + String.valueOf(ans.charAt(i) );
                }
                else{
                   count++;
                   tempAns = tempAns + String.valueOf(count) + String.valueOf(ans.charAt(i-1) );
                }
            }
        }
        return tempAns;
    }
}
