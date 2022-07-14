class Solution {
    public int kthGrammar(int n, int k) {
        if( n == 1 && k == 1){
            return 0;
        }
        int mid = ( (int) Math.pow(2, n-1) ) / 2;
        
        if(k<= mid){
          return  kthGrammar( n-1 , k);
        }
        else{
           int ans = ( kthGrammar( n-1, k-mid ) );
            if(ans==1)
                return 0;
            else
                return 1;
        }
    }
    
}
