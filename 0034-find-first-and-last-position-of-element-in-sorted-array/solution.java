class Solution {
    public int[] searchRange(int[] nums, int target) {
       int[] arr={-1,-1};
         arr[0]=binarySearch(nums,target,true);
        if(arr[0] ==-1)
            return arr;
         arr[1]=binarySearch(nums,target,false);
        return arr;      
            
    }
    
    int binarySearch(int[] nums,int target, boolean isFirstPosition){
        int start=0 ;
        int end=nums.length-1;
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                if(isFirstPosition){
                    ans=mid;
                    end=mid-1;
                }
                else{
                    ans=mid;
                    start=mid+1;
                }
            }
            else if(nums[mid]>target){
               end=mid-1; 
            }
            else{
                start=mid+1;
            }
                
        }
        return ans;
    }
}
