class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int n= piles.length;
        //base case
        if(n > h) return -1;
        
        int maxi=piles[0];
        for(int i=0; i<n; i++){
            maxi = Math.max( maxi, piles[i]);
        }
        
        int low=1, high = maxi, ans = -1;
        while( low <= high){
            int mid = low + (high - low)/2;
            
            if( isPossibleWithKbanana(mid, piles, h)){
                ans = mid;
                high= mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    public boolean isPossibleWithKbanana(int capacity, int []piles, int h){
        int time =0;
        for(int i=0; i<piles.length; i++){
            if( piles[i] % capacity == 0)
                time  = time + piles[i]/capacity;
            else{
                time = time + ( piles[i]/capacity ) +1;
            }
            
            if(time > h) return false;
        }
        if( time <= h) return true;
        return false;
    }
}
