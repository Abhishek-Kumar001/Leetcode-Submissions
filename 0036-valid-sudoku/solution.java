
// class Solution {
//     public boolean isValidSudoku(char[][] board) {
//         int n= board.length;
//         for(int i=0; i<n; i++){
//            for(int j=0; j<n; j++){
//                if( board[i][j] != '.'){
//                    if( isValid(i, j, board, board[i][j], n) == false){
//                        return false;
//                    }
//                }
//            }
//         }
//         return true;
//     }
//     public boolean isValid(int row, int col, char[][] board, char val, int n) {
//         // Row wise checking
//         for (int i = 0; i < n; i++) {
//             if (i != col && board[row][i] == val) {
//                 return false;
//             }
//         }
//         // Column wise checking
//         for (int i = 0; i < n; i++) {
//             if (i != row &&  board[i][col] == val) {
//                 return false;
//             }
//         }
//         // Box wise checking
//         int boxRowStart = 3 * (row / 3);
//         int boxColStart = 3 * (col / 3);
//         for (int i = boxRowStart; i < boxRowStart + 3; i++) {
//             for (int j = boxColStart; j < boxColStart + 3; j++) {
//                 if ((i != row || j != col)  && board[i][j] == val) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// }




class Solution {
    public boolean isValidSudoku(char[][] board) {
        int n = board.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    if (!isValid(i, j, board, board[i][j], n)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public boolean isValid(int row, int col, char[][] board, char val, int n) {
        // Row wise checking
        for (int i = 0; i < n; i++) {
            if (i != col && board[row][i] == val) {
                return false;
            }
        }
        // Column wise checking
        for (int i = 0; i < n; i++) {
            if (i != row && board[i][col] == val) {
                return false;
            }
        }
        // Box wise checking
        int boxRowStart = 3 * (row / 3);
        int boxColStart = 3 * (col / 3);
        for (int i = boxRowStart; i < boxRowStart + 3; i++) {
            for (int j = boxColStart; j < boxColStart + 3; j++) {
                if ( (i != row || j != col) && board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
}

