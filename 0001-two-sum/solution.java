class Solution {
    public int[] twoSum(int[] nums, int target) {
        //copy all elements in temp array b/c when we sort the index will change of all elem.
        int temp[]= new int[nums.length];
        for(int i=0; i< nums.length; i++){
            temp[i] = nums[i];
        }
        // 1st of all sort the array
        Arrays.sort(nums);
        
        int start=0, end=nums.length-1;
        while(start < end){
           if(  (nums[start] + nums[end] )  ==  target){
               // find index of nums[start]  and nums[end] in temp array
               int s=0,e=0;
               for(int i=0; i<nums.length; i++){
                   if(temp[i] == nums[start]){
                     s= i;
                     break;       //vvi
                   }                  
               }
               //to find nums[end]  run loop from end
               for(int i=nums.length-1; i>=0; i--){
                   if(temp[i] == nums[end]){
                      e= i;
                      break;    //vvi
                   }  
               }
               return new int[]{ s, e};
           }
           else if(  (nums[start] + nums[end] )  >  target){
              end--;
           }
           else{
               start++;
           }
        }
        return new int[]{start , end};  // ye kabhi execute nhi hoga par return toh likhna hi padtra hai
    }
}
