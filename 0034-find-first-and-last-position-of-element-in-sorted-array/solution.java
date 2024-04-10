class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n= nums.length;
        
        // finding 1st occurence
        int first = -1;
        int s=0, e = n-1;
        while( s<=e){
            int mid = (s+e)/2;

            if( nums[mid] == target){
                 first = mid;
                 e =mid-1;
            }else if( nums[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        int ans[] = new int[2];
        if( first == -1){
            ans[0] = -1;
            ans[1] = -1;
             return ans;
        }

        ///  finding last occurence
        int second = -1;
         s=0;
         e = n-1;
        while( s<=e){
            int mid = (s+e)/2;

            if( nums[mid] == target){
                 second = mid;
                 s =mid+1;
            }else if( nums[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        ans[0] = first;
        ans[1] = second;
        return ans;
    }
}
