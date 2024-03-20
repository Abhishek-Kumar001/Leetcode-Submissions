class Solution {
    public int searchInsert(int[] nums, int target) {
        int s=0; int e= nums.length-1;
        int ansInd= nums.length;
        while( s<=e){
            int mid = (s+e)/2;
            if( nums[mid] >= target){
                ansInd = mid;
                e = mid-1;
            }
            else{
                s= mid+1;
            }
        }
        // if( nums[nums.length-1] < target) return nums.length;
        return ansInd;
    }
}
