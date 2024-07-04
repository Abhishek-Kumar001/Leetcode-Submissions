class Solution {
    public int removeDuplicates(int[] nums) {
            //copy past from discussion
        // int j = 1;
        // for (int i = 1; i < nums.length; i++) {
        //     if (j == 1 || nums[i] != nums[j - 2]) {
        //         nums[j++] = nums[i];
        //     }
        // }
        // return j;
      

             // my code 
        int j=1;
        for(int i=2; i<nums.length; i++){
            if(nums[i] != nums[j-1]){
                //swap
                nums[j+1] = nums[i];
                j++;
            }
        }
        return j+1;
    }
}
