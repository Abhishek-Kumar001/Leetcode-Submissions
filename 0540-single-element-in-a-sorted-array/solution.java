// tc = O(n)
// Solution {
//     public int singleNonDuplicate(int[] nums) {
//         int ans = 0;
//         for(int i=0; i<nums.length; i++){
//             ans^=nums[i];
//         }
//         return ans;
//     }    
// }


// TC- O(log n)  
class Solution {
    public int singleNonDuplicate(int[] nums) {
        //corner case 
        if( nums.length  == 1) return nums[0];
        
        for(int i=1; i<nums.length; i=i+2){
            if( nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }
        return nums[nums.length-1];  // handling odd length arrray
    }    
}
