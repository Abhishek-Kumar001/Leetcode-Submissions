class Solution {
    public int missingNumber(int[] nums) {
         int s=0;int end=nums.length-1;
        int ans=nums.length;
        while(s<=end) {
           int correct=nums[s];
           
            if(nums[s]<=end && nums[s]!=nums[correct]){
                int temp=nums[s];
                nums[s]=nums[correct] ;
                nums[correct] =temp;
            } 
            else 
                s++;
        } 
        for(int i=0;i<nums.length;i++)
            if(nums[i]!=i)
                return i;
         
        return ans;
    }
}
