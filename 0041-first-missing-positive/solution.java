class Solution {
    public int firstMissingPositive(int[] nums) {
        
        int s=0;
        int end=nums.length-1;
        while(s<=end){
            int correct=nums[s];
            
            if(nums[s]>=0 && nums[s]<=end && nums[s]!=nums[correct]){
                int temp =nums[s];
                nums[s]=nums[correct];
                nums[correct]=temp;
            }
            else
                s++;
        }
        /* if(nums.length==1){
            if(nums[0]==1)
                return 2;
            else  
            return 1;
        }  */
        for(int i=1;i<=end;i++)
            if(nums[i]!=i)
                return i;
        if(nums[0]!=end+1)
        return end+1;
        else
            return end+2;
    }
}
