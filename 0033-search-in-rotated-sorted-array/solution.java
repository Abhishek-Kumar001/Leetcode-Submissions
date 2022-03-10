class Solution {
    public int search(int[] nums, int target) {
        int index=0;
        if(nums[0]>nums[nums.length-1]){
           index=pivote(nums);
       
           if(target>=nums[0] && target<=nums[index])
               return  binarySearch(nums,target,0,index);
           else if(target>=nums[index+1] && target<=nums[nums.length-1])
                return binarySearch(nums,target,index+1,nums.length-1); 
           else   return -1;
        }
        else
           return  binarySearch(nums,target,0,nums.length-1);
       // return -1;
    }
    public int pivote(int a[]){
      int s=0,e=a.length-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(a[mid]>a[mid+1])
                return mid;
            else if(a[mid]>=a[0])
                  s=mid+1;
            else    
                  e=mid-1;
        }
        return -1;
    }
    public int binarySearch(int nums[],int target,int s,int e){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                e=mid-1;
            else
                s=mid+1;
        }
        return -1;
    }
}
