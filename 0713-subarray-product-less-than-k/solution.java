// class Solution {
//     public int numSubarrayProductLessThanK(int[] nums, int k) {
//         if(k == 0) return 0;
//         int cnt=0;
//         for(int i=0; i<nums.length; i++){
//             long prod=1;
//             for(int j=i; j<nums.length; j++){
//                 prod*=nums[j];
//                 if(prod < k)
//                   cnt++;
//                 else break;
//             }
//         }
//         return cnt;
//     }
// }

class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        // @ yt- code bashers
        if(k == 0) return 0;
        int cnt=0, end = 0, start=0, product = 1;
        while(end < nums.length){
            product*=nums[end];

            while(start < end && product >= k){
                product/=nums[start];
                start++;
            }

            if( product < k) cnt+=end-start+1;

            end++;
        }
        return cnt;
    }
}
