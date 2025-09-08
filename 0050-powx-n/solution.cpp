class Solution {
public:
    double myPow(double x, int n) {
        // corner case
        if(n == 0) return 1;

        long long nn = n;
        if(nn < 0 ) nn = -nn;
        double ans = 1;
        while(nn){
            if(nn % 2 == 0){
                x = x*x;
                nn /=2;
            }else{
                ans *= x;
                nn--;
            }
        }

        if(n < 0) return 1/ans;
        return ans;
    }
};
