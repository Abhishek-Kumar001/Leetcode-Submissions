class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int sum = 0;
        int left = 0;
        int miniSize = Integer.MAX_VALUE;
        for(int i=0;i<nums.length; i++){
            sum+=nums[i];

            while(left <= i && sum >= target){
                miniSize = Math.min(miniSize, i-left+1);
                sum-=nums[left++];
            }
        }
        if(miniSize == Integer.MAX_VALUE) return 0;
        return miniSize;
    }
}
