class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int[] prev = new int[m];
        for (int i = 0; i < m; i++) {
            prev[i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            int[] curr = new int[m];
            for (int j = 0; j < m; j++) {
                int leftDiagonal = Integer.MAX_VALUE;
                if (j > 0) leftDiagonal = prev[j - 1];
                int up = prev[j];
                int rightDiagonal = Integer.MAX_VALUE;
                if (j < m - 1) rightDiagonal = prev[j + 1];

                curr[j] = matrix[i][j] + Math.min(leftDiagonal, Math.min(rightDiagonal, up));
            }
            prev = curr;
        }

        int maxi = prev[0];
        for (int i = 1; i < m; i++) {
            maxi = Math.min(maxi, prev[i]);
        }

        return maxi;
    }
}
