class Tuple{
    int time, row , col;
    public Tuple(int t, int r, int  c){
        time = t;
        row = r;
        col = c;
    }
}
class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        int [][]visited = new int[n][m];
        Queue<Tuple> q = new LinkedList<>();
        int cntFresh = 0;
        for( int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.add(new Tuple(0, i, j));
                    visited[i][j] = 1;
                }
                else if(grid[i][j] == 1){
                    cntFresh++;
                }
            }
        }
        
       int time =0;
       int cnt=0;
       int drow[] = { 0, +1, 0,-1};
       int dcol[] = {+1, 0, -1, 0};
        
        while(q.size() >= 1){
            Tuple t = q.remove();
            time = t.time;
            int r = t.row;
            int c = t.col;
            
            for( int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if( nrow>=0 && nrow<n && ncol >=0 && ncol <m  &&
                         visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    
                    visited[nrow][ncol] = 1;
                    q.add( new Tuple(time+1, nrow, ncol));
                    cnt++;
                }
            }
        }
        
        if( cnt < cntFresh) return -1;
        return time;
    }
    
    
}
