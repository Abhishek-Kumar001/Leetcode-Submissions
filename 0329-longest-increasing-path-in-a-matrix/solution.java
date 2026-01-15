class Solution {

    int[][] matrix;
    int[][] dp;
    int n, m;

    int[] drow = {0, 1, 0, -1};
    int[] dcol = {1, 0, -1, 0};

    public int longestIncreasingPath(int[][] matrix) {
        this.matrix = matrix;
        n = matrix.length;
        m = matrix[0].length;

        dp = new int[n][m]; // memo table

        int ans = 1;

        // try starting from every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = Math.max(ans, dfs(i, j));
            }
        }

        return ans;
    }

    private int dfs(int r, int c) {
        // already computed
        if (dp[r][c] != 0) return dp[r][c];

        int maxLen = 1; // path includes this cell

        for (int k = 0; k < 4; k++) {
            int nr = r + drow[k];
            int nc = c + dcol[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                matrix[nr][nc] > matrix[r][c]) {

                maxLen = Math.max(maxLen, 1 + dfs(nr, nc));
            }
        }

        dp[r][c] = maxLen;
        return maxLen;
    }
}

