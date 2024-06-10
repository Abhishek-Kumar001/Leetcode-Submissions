class Solution {
    public int strStr(String haystack, String needle) {
        int n=haystack.length(), m=needle.length();
        for(int i=0; i<haystack.length(); i++){
            if(haystack.charAt(i) == (needle.charAt(0))){
                int k = i, j=0;
                int cnt= 0;
                while(k<n && j<m){
                    if( haystack.charAt(k++) != needle.
                                 charAt(j++)  )
                    {
                       break;
                    }
                    cnt++;
                }
                // if we r here then there may be 2 cases
                //case1: hame sequence nahi mila and hm 
                       // bich me se hi break kar gye 
                // case2:- hame sequence mil gya hai
                if(cnt == m) return i; // case 2 
            } 

            if(i > n-m) break;  //ab to m characters to
            // bacha v nhi hai to aage khun hi check karna
        }
        return -1;
    }
}
