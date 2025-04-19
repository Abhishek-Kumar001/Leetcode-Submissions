class Solution {
    double helper(double x,  long long n, double ans){
        // base case 
        if(n == 0) {
            return ans;
        }

        if(n % 2 == 1){
            ans *= x;
        }

        x*=x;
        n = n/2;
        ans = helper(x, n, ans);
        
        return ans;
    }
public:
    double myPow(double x, int n) {
       double ans = 1;
       long long nn = n;
       nn = abs(nn);
       ans = helper(x, nn, ans);

       if(n < 0) {
        return 1/ ans;
       }
       return ans;
    }
};



