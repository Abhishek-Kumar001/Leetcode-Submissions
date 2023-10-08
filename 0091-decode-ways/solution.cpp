// my code 228/269 TEST CASE PASS
class Solution {
    private:
    int helper( int ind, int n, string s, vector<int> &dp){
        // base case 
        if( ind == n) return 1;
        if( ind > n) return  0;

        if( dp[ind] != -1) return dp[ind];

        //one digit
        int one = 0;
        if(s[ind] != '0'){
            one = helper( ind+1, n, s, dp);
        }
        // go two steps
        int two = 0;
        if( s[ind] == '1'  ||  (s[ind] =='2'  && s[ind+1] <='6' ) ){  // V V I TEST CASE 
            two = helper(ind+2, n, s, dp);
        } 
        
        return dp[ind] = one + two;
    }
public:
    int numDecodings(string s) {
        // corner case 
        if( s[0] == '0') return 0;

        int n = s.length();
        vector<int> dp(n+1, -1);
        return helper( 0, n, s, dp);
    }
};
