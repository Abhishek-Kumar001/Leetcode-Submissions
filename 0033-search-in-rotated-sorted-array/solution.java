class Solution {
    public int search(int[] nums, int target) {
        int s=0, e=nums.length-1;
        
        int ansInd =0;
        while( s <= e){
            int mid = (s+e)/2;
            if( nums[mid] == target){
                return mid;
            }
            
            if( nums[s] <= nums[mid]){
                // it means 1s  half is sorted so apply binary search logic to find
                if( target >= nums[s]  && target <= nums[mid]){
                     e = mid-1;
                }
                else{
                    //ans lies in 2nd(unsorted half)
                    s = mid+1;
                }
            }
            else{
                // 2nd half is sorted
                if( target >= nums[mid]  && target <= nums[e]){
                      s = mid+1;
                }
                else{
                    e = mid -1;
                }
            }
        }
        return -1;
        
    }
}
