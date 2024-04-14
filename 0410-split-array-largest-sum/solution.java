class Solution {
    public int splitArray(int[] nums, int k) {
        
        //corner or base case
        if( k > nums.length) return -1;

        //find maxi and arrSum
        int maxi=nums[0], arrSum = 0;
        for( int it : nums){
            maxi = Math.max(maxi, it);
            arrSum +=it;
        }

        int low = maxi;
        int high = arrSum;
        int ans = -1;

        while( low <= high){
            int mid = low + (high - low)/2;

            if( isPossibleWithKpages(mid, nums, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;    
    }
    
    public boolean isPossibleWithKpages(int pages, int []arr, int k){
        int cntStd = 0;
        int pg = pages;
        for( int it : arr){
            if( it <= pg){
                pg-=it;
            }else{
                cntStd++;
                pg = pages - it;  // pages not pg // VVI
            }
        }
        cntStd++;
        return cntStd <= k;
}
}
