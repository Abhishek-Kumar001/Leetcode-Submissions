class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;

        int dp[][] = new int[n][n];
        for(int i=0; i<n; i++) dp[0][i] = matrix[0][i];

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = dp[i-1][j];

                int leftDiagonal = Integer.MAX_VALUE;
                if(j > 0)
                   leftDiagonal = dp[i-1][j-1];

                int rightDiagonal = Integer.MAX_VALUE;
                if(j+1 < n)
                    rightDiagonal = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + Math.min(up, Math.min(leftDiagonal, rightDiagonal));
            }
        }

        int ans = Integer.MAX_VALUE;
        for(int i=0; i<n; i++){
            ans = Math.min(ans, dp[n-1][i]);
        }

        return ans;
    }
}
