class NumMatrix {
    vector<vector<int>> prefixMatrix; 
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return ;
        int m = matrix[0].size();
        prefixMatrix.resize(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            // prefixMatrix[i][0] = matrix[i][0];
            for(int j=1; j<=m; j++){
                prefixMatrix[i][j] = prefixMatrix[i-1][j] + prefixMatrix[i][j-1] - prefixMatrix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       return prefixMatrix[row2+1][col2+1] - prefixMatrix[row2+1][col1] - prefixMatrix[row1][col2+1] + prefixMatrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
