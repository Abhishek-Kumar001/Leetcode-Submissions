
                           // TLE
// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         string t = s;
//         reverse(t.begin(), t.end());

//         int n = s.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
//         int maxi = 0;

//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=n; j++){
//                 if(s[i-1] == t[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }else{
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
                
//                 if(dp[i][j] >= maxi){
//                     maxi = dp[i][j];
//                 }
//             }
//         }

//         for(int i=0; i<=n; i++){
//             for(int j=0; j<=n; j++){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }

//         return maxi;
//     }
// };


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        int maxi = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                   curr[j] = max(prev[j], curr[j-1]);
                }
                
                if(curr[j] >= maxi){
                    maxi =curr[j];
                }
            }
            prev = curr;
        }

        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=n; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return maxi;
    }
};
