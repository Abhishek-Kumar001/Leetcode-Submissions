class Solution {
public:
    int reverse(int x) {
        if(x==0)  return 0;
        int rev=0;
       while(x!=0)
       {
           int rem=x%10;
            if ((rev > INT_MAX/10) || (rev < INT_MIN/10) )  return 0;
           rev=rev*10+rem;
           x/=10;
       }
     
        
       // if(x> INT_MAX  || x<INT_MIN)
       //     return 0;
       //else return x;
        return rev;
    }
};
