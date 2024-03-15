class Solution {
    public int majorityElement(int[] nums) {
        int curr = nums[0];
        int cnt=1;
        
        for( int i=1; i<nums.length; i++){
            if( nums[i] == curr){
                cnt++;
            }
            else{
                cnt--;
                if( cnt == 0){
                    curr = nums[i];
                    cnt=1;
                }
            }
        }
        return curr;
    }
}
