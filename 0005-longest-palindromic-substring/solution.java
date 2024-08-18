// class Solution {
//     public String longestPalindrome(String s) {
//         int n = s.length();
//         String t = "";
//         // now reverse t
//         for(int i=n-1; i>=0; i--) t+=s.charAt(i);

//         int dp[][] = new int[n+1][n+1];

//         int maxi =0, ii=0, jj=0;
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=n; j++){
//                 if(s.charAt(i-1) == t.charAt(j-1) ){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }
//                 if(maxi < dp[i][j]){
//                     maxi = dp[i][j];
//                     ii = i; jj= j;
//                 }
//             }
//         }

//         int len = dp[n][n];
//         String ans = "";
//         while(ii > 0 && jj > 0){
//             if(s.charAt(ii-1) == t.charAt(jj-1) ){
//                 ans+= s.charAt(ii-1);
//             }
//             ii--; jj--;
//         }

//         return ans;
//     }
// }
                // #@ chatgpt code
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        String t = new StringBuilder(s).reverse().toString(); // Reverse the string

        int dp[][] = new int[n+1][n+1];

        int maxi = 0, end = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s.charAt(i-1) == t.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];

                    // Check if the start index of the palindrome in the original string aligns correctly
                    int startInOriginal = i - dp[i][j];
                    int startInReverse = n - j;

                    if (startInOriginal == startInReverse && dp[i][j] > maxi) {
                        maxi = dp[i][j];
                        end = i;
                    }
                }
            }
        }

        return s.substring(end - maxi, end); // Return the longest palindromic substring
    }
}

