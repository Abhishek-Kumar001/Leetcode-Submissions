
// class Solution {
//     public int threeSumClosest(int[] nums, int target) {
//         int target1 = 0; // grater than or equal to target
//         Arrays.sort(nums);
//         for( int i=0; i<nums.length; i++) System.out.print( nums[i]);
//         System.out.println();
//         for(int i=0; i<nums.length-2; i++){
//             int s = i+1;
//             int e = nums.length-1;
//             int sum = nums[i];
            
//             while( s<e){
//                 if( (nums[i] + nums[s] + nums[e])  >= target){
//                     target1 = sum;
//                     e--;
//                 }
//                 else  s++;
//             }
//         }
        
        
//         int target2 = 0;  // smaller or equal to target
//         for(int i=0; i<nums.length-2; i++){
//             int s = i+1;
//             int e = nums.length-1;
//             int sum = nums[i];
            
//             while( s<e){
//                 if( (nums[i] + nums[s] + nums[e])  <= target){
//                     target2 = sum;
//                     s++;
//                 }
//                 else  e--;
//             }
//         }
//         System.out.println( target1 + "  " + target2);
//         //if(target1 == target2) return target1;
        
//         if( Math.abs(target- target1) <= Math.abs(target- target2) ){
//             return target1;
//         }
//         else return target2;
//     }
// }





import java.util.Arrays;

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the sum of the                                                         //first three elements

        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (Math.abs(sum - target) < Math.abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
}

