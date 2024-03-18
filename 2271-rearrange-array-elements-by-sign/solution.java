class Solution {
    public int[] rearrangeArray(int[] a) {
        int cntPos =0;
        int cntNeg=0;
        int temp[] = new int[a.length];
        for(int i=0; i<a.length; i++){
            if( a[i] < 0)  cntNeg++;
            else cntPos++;
        }

        int n=1;
        int p =0;
        int min = Math.min( cntPos, cntNeg);
        for(int i=0; i<min*2; i++){
            if( a[i] < 0){
                temp[n] = a[i];
                n+=2;
            }
            else{
                temp[p] = a[i];
                p+=2;
            }
        }
        for( int i=2*min; i<a.length; i++){
           temp[i] = a[i];
        }
        
        return temp;
    }
}
