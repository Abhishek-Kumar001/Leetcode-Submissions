class Solution {
public:
    bool isPowerOfTwo(int n) {
     if(n<=0) return false;
       int ans=1;
   
      for(int i=0;i<=30;i++) 
       {
  
           if(n==ans) 
               return true;
           if(ans<INT_MAX/2) 
               ans*=2;
       }  
        return false;
        
   
    }
};
