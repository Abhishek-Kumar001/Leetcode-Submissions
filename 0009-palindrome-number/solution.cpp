class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0)  return true;
        if(x<0)  return false;
      int no=x;
      int rev=0;
        while(no!=0)
        {
          int rem=no%10;
            if(rev>INT_MAX/10  ||  rev < INT_MIN/10)    return false;
            rev=rev*10+rem;
            no/=10;
        }
        if(rev==x)
            return true;
        else 
            return false;
    }
};
