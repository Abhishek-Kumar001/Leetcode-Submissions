class Solution {
    public int maxSubArray(int[] nums) {
        int sum=nums[0];
        int temp_sum=0;
        int start=0;
        while(start<nums.length){
          temp_sum+=nums[start];
            
            if(temp_sum > sum){
                sum=temp_sum;
            }
            
            if(temp_sum<=0){
               temp_sum=0;
            }
                
            start++;
        }
            return sum;
    }
}
