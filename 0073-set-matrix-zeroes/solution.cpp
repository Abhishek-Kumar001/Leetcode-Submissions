class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n = matrix[0].size();

        vector<int> colMarker(n, 1);
        vector<int> rowMarker(m, 1);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    rowMarker[i] = 0;
                    colMarker[j] = 0;
                }
            }
        }

        // now setting the matrix to zero a/c to question
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rowMarker[i] == 0  || colMarker[j] ==0 ){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
