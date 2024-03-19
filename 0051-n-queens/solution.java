class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ansList = new ArrayList<>();
        List<List<Integer>> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                row.add(0); // Fill the board with zeroes initially
            }
            board.add(row);
        }

        helper(0, board, ansList, n);

        return ansList;
    }
    
    public static boolean isSafe( int row, int col, List<List<Integer>> board, int n){
        // row wise check
        for( int c = col-1; c >= 0; c--){
            if( board.get(row).get(c)  == 1){
                return false;
            }
        }
        // updiagonal check
        int r=row;
        int c = col;
        while( r >=0 && c >= 0){
            if( board.get(r).get(c)  == 1) return false;
            r--; c--;
        }

        // bellow diagonal chaek
        while( row<n && col>=0){
            if( board.get(row).get(col) == 1) return false;
            row++;
            col--;
        }

        return true;
    }
    public static void helper(int col,  List<List<Integer>> board,  List<List<String>>         ansList, int n){
        if( col == n){
            List<String> temp = new ArrayList<>();
            for( int i=0; i<n; i++){
                String s = "";
                for(int j =0; j<n; j++){
                   if( board.get(i).get(j) == 0 ){
                       s = s+".";
                   }else s = s+"Q";
                }
                temp.add(s);
            }
            ansList.add( temp);
            return ;
        }

        for(int row=0; row<n; row++){
            if( isSafe( row, col, board, n ) ) {
                 board.get(row).set(col, 1);
                 helper( col+1, board, ansList, n);
                 board.get(row).set(col, 0);
            }
        }
        
    }
}
