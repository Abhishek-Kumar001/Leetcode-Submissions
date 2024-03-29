class Solution {
public:
    bool isSafe( int val, vector<vector<char>>& board, int row, int col){
        for( int i=0; i<9; i++){
            // row wise checking
            if( board[row][i] == val) return false;
            //col wise checking
            if( board[i][col] == val) return false;

            if( board[3*(row/3)+i/3][3*(col/3)+i%3]  == val) return false;
        }
        return true;

    }

    bool sudokuSolver(vector<vector<char>>& board) {
        /* Don't write main().
         *  Don't read input, it is passed as function argument.
         *  Don't print output and return output as specified in the question
        */

        for( int i=0; i<9; i++){
            for( int j=0; j<9; j++){
                if( board[i][j] == '.'){
                    for( int val='1'; val<='9'; val++){
                        if( isSafe( val, board, i, j)){
                            board[i][j] = val;

                            bool asp = sudokuSolver(board);
                            if( asp) return true;
                            else{
                                //backtrack
                                board[i][j] = '.';
                            } 

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board);
    }
};
