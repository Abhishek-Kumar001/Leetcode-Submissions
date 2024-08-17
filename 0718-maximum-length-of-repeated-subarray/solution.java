class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        // this code is same like longest common subsequence of string 
        int n1 = nums1.length, n2= nums2.length;

        int [][]dp = new int[n1+1][n2+1];
        int maxLen = 0;
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else dp[i][j] = 0;  //  no need of this line b/c 
                // in java all array elements are initialize with 0 only

                maxLen = Math.max(maxLen, dp[i][j]);
            }
        }
        return maxLen;
    }
}
