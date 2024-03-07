class Solution {
public:
    void pow( double x, int n, double &ans){
        if( n == 0) return ;
        
        if(n&1){
            ans = ans*x;
        }
        pow(x*x, n/2, ans);
    }
    double myPow(double x, int n) {
        // STRIVER APP
        double ans = 1.0;
        long nn=n;
        if( nn<0) nn= -1*nn;
        
        pow(x, nn, ans);
        if( n <0) ans = (double) 1.0 / ans;
        return ans;
    }
};
