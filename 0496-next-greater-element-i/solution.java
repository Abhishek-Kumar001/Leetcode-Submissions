class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
       
        int[]  ans = new int[nums1.length];
        
        for(int i=0; i<nums1.length ; i++){
            int data=nums1[i];
            int j=0, mark=0;
            for( j=0; j<nums2.length ; j++){
               if(nums2[j] == data){
                   mark=j;
                   break;
               }
            }

            //case 1 (if we not reach to the end go forward and find greater)
            for( j= mark +1 ; j<nums2.length ; j++){
                if(nums2[j] > data){
                   ans[i]= nums2[j];
                    break;
                }
            }
            // case 2 (if we reach to end of array)
            if(j == nums2.length )
               ans[i]=-1; 
        }
        
        return ans;
    }
}
