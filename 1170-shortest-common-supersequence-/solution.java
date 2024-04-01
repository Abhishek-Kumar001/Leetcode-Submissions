class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int n=str1.length();
        int m=str2.length();
        
        int dp[][] = new int[n+1][m+1];
        
        for( int i=1; i<=n; i++){
            for( int j=1; j<=m; j++){
                if(str1.charAt(i-1) == str2.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = Math.max( dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        //kahani ab suru hoti hai
        String ans = "";
        int i=n, j=m;
        
        while( i>0  && j>0){
            if( str1.charAt(i-1) == str2.charAt(j-1)){
                ans+=str1.charAt(i-1);
                i--; j--;
            }
            else if( dp[i][j-1] > dp[i-1][j]){
                ans+=str2.charAt(j-1);
                j--;
            }
            else{
                ans+=str1.charAt(i-1);
                i--;
            }
        }
        
        //vvi part
        while( i >0){
            ans+=str1.charAt(i-1);
            i--;
        }
        while( j>0){
            ans+=str2.charAt(j-1);
            j--;
        }
        
        String revAns = "";
        for(int k=ans.length()-1; k>=0; k--){
            revAns+=ans.charAt(k);
        }
        return revAns;
    }
}
