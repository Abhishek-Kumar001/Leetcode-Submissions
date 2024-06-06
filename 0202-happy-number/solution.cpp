class Solution {
public:
    bool isHappy(int n) {
        map<int,int> mpp;
        while(n){   // this loop only braek when we find ans 
                    // b/c for sure n is never gone to 0 it will only 
                    // be going to bigger no 
        
            // calculating sum of square of digits of no
            int sum = 0;
            while(n){
                sum+=((n%10)*(n%10));
                n/=10;
            }

            if(sum == 1) return true;  
            if( mpp.find(sum) != mpp.end()){
                return false;  // we are repeting the now, i.e we will gone in endless loop 
            }
            mpp[sum]++;

            n = sum;
        }
        return true; // we will never come to this line definitely 
    }
};
