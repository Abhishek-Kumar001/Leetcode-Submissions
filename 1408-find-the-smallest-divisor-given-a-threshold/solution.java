class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        // Write your code here.
        int n= nums.length;
        //corner case
        if( threshold < n) return -1;

        int maxi=nums[0];  // no need of mini
        for( int it : nums){
            if(it > maxi) maxi = it;
	    }
        
        int low = 1, high= maxi;
        int ans = -1;
        while( low <= high){
            int mid = low + (high - low )/2;

            if( isSumLessThanLimit( mid, nums, threshold)){
                ans = mid;
                high= mid-1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
    
    public boolean isSumLessThanLimit(int divisor, int []arr, int limit){
        int quotientSum =0;
        for( int it  : arr){
            quotientSum += Math.ceil( (double)it / (double)divisor);
        }

        return ( quotientSum <= limit);
    }
}
