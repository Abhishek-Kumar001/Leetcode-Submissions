// // recursive
// class Solution {
//     private:
//     int helper(int i, int j, string &word1, string &word2){
//         if(j<0) return i+1;
//         if(i<0) return j+1;

        
//         if(word1[i] == word2[j]){
//           return helper(i-1, j-1, word1, word2);
//         }else{
//            return min({
//                 1 + helper(i - 1, j - 1, word1, word2),  // Replace
//                 1 + helper(i - 1, j, word1, word2),      // Delete
//                 1 + helper(i, j - 1, word1, word2)       // Insert
//             });
//         }
//     }
// public:
//     int minDistance(string word1, string word2) {
//         return helper(word1.length()-1, word2.length()-1, word1, word2);
//     }
// };




// tabultion
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n  = word1.length();
        int m  = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][0] = i;
                dp[0][j] = j;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min( dp[i][j-1], dp[i-1][j]));
                }
            }
        }

        return dp[n][m];
    }
};


