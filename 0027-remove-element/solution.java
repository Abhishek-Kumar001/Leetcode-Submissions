class Solution {
    public int removeElement(int[] nums, int val) {
        int ind = nums.length;
        for( int i=0; i<nums.length; i++){
            if( nums[i] == val){
                ind = i;
                break;
            }
        }
        
        for(int i = ind+1; i<nums.length; i++){
            if( nums[i] != val){
                //swap
                int temp = nums[ind];
                nums[ind] = nums[i];
                nums[i] = temp;
                
                ind++;
            }          
        }
        return ind;
    }
}
