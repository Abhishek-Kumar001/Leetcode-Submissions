class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rowSize = mat.size(), colSize = mat[0].size();
        
        // create a vector which store the row & col of each element of mat matrix
        vector<pair<int, int>> matValueIndexTracker(arr.size()+1, {0, 0});

        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                int val = mat[i][j];
                matValueIndexTracker[val] = {i, j};
            }
        }
        
        //crete a row counter array which keeep track of at which row how many 
        // elements are painted 
        // create a array  for colums also  to keep the track
        vector<int> nTh_rowCounter(rowSize, 0);
        vector<int> nTh_colCounter(colSize, 0);

        // now traverse the arr and pain the elements of mat and update the
        // painted cnt of that row and column
        for(int i=0; i<arr.size(); i++){
            int x = arr[i];
            int row = matValueIndexTracker[x].first;
            int col = matValueIndexTracker[x].second;

            nTh_rowCounter[row]++;
            // return if all the elements of this row got painted
            // but compare with colSize  *** vvvi **
            if(nTh_rowCounter[row] == colSize) return i;

            nTh_colCounter[col]++;
            // return if all the elements of this column got painted
            // but compare with colSize  *** vvvi **
            if(nTh_colCounter[col] == rowSize )  return i;
        }

        return -1; // this just for the compiler

    }
};
