class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int n= weights.length;
        //corner case
        if( days == 0) return -1;

        //find min and max
        int maxi= weights[0];
        int sum =0;
        for( int it : weights){
            if( it > maxi) maxi= it;
            sum+=it;
        }

        //now do binary search and find ans
        int low =maxi, high= sum, ans=-1;

        while( low <= high){
            int mid = low + (high-low)/2;

            if( isPossibleToShipWithMidWeight( mid, weights, days)){
                ans = mid;
                //find more less capacity
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    public boolean isPossibleToShipWithMidWeight(int wt, int []weights, int d){
         int cntDays = 0;
         int w = wt;
         for( int it : weights){
            if( it <= w){
                w = w-it;
            }else{
                cntDays++;
                w = wt-it;
            }
         }
        cntDays++;
        return cntDays<=d;
   }
}
