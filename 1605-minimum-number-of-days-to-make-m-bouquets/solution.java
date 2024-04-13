class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int n= bloomDay.length;
        
        //corner case handling
        
        // long val = m * k;
        // if( val > n) return -1;
        
        if(m > (n / k)) return -1;
        
        int maxi = bloomDay[0], mini = bloomDay[0];
        for(int i=0; i<n; i++){
            if( bloomDay[i] < mini) mini= bloomDay[i];
            if( bloomDay[i] > maxi) maxi = bloomDay[i];
        }
        
        int ans=0;
        int low = mini, high = maxi;
        while( low <= high){
            int mid = low + (high - low)/2;
            
            if( isPossible( mid, bloomDay, m, k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid +1; 
            }
        }
        return ans;
    }
    
    public boolean isPossible( int day, int []bloomDay, int m, int k){
        int noOfBouquets = 0;
        int cnt = 0;
        for( int i=0; i<bloomDay.length; i++){
            if( bloomDay[i] <= day){
                cnt++;
            }else{
                noOfBouquets+=(cnt/k);
                cnt =0;
            }
        }
        noOfBouquets+=(cnt/k);
        return noOfBouquets>=m;
    }
}
