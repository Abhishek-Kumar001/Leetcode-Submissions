class Tuple{
    int val, row, col;
    public Tuple(int v, int r, int c){
        val = v; row = r; col = c;
    }
}
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        int n= grid.length;
        int[][] visited = new int[n][n];
        // **NO NEED OF MIN HEAP**, IT Can be solved by queue also
        Queue<Tuple> q = new LinkedList<>();
        int srcRow = 0;
        int srcCol = 0;
        //base case;
        if( grid[srcRow][srcCol] == 1)  return -1;
        int desRow = n-1;
        int desCol = n-1;


        visited[srcRow][srcCol] = 1;
        // start with cnt=1 b/c A/c if sec and des is same return 1; not 0;
        q.add(new Tuple(1, srcRow, srcCol));

        while( !q.isEmpty()){
            int cnt = q.peek().val;
            int row= q.peek().row;
            int col = q.peek().col;
            q.remove();

            if( row == desRow  && col == desCol) return cnt;

            for(int i=-1; i<=1; i++){
                for( int j=-1; j<=1; j++){
                    int nrow = row + i;
                    int ncol = col + j;

                    if( nrow>=0  && nrow<n && ncol>=0 && ncol<n && visited[nrow][ncol]== 0
                        && grid[nrow][ncol]== 0){

                           visited[nrow][ncol] = 1;
                           q.add(new Tuple(cnt+1, nrow, ncol));
                    }
                }
            }
        }
        return -1;
    }
}

