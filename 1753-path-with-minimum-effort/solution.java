class Tuple{
    int diff,  row,  col;
    public Tuple(int d, int r, int c){
        diff = d; row = r; col = c;
    }
}
class Solution {
    public int minimumEffortPath(int[][] heights) {
        
        //  @ striver tarika
        int n= heights.length, m = heights[0].length;
        
        int [][]dist = new int[n][m];
        for( int i=0; i<n; i++)
            for( int j=0; j<m; j++)
                dist[i][j] = (int)(1e9);
        
        PriorityQueue<Tuple> pq = new PriorityQueue<Tuple>((x,y)->x.diff - y.diff);
        pq.add( new Tuple(0,0,0));
        
        int drow[] = {0, +1, 0, -1};
        int dcol[] = {+1, 0, -1, 0};
        while( !pq.isEmpty()){
            Tuple t = pq.peek();
            pq.remove();
            int diff = t.diff;
            int row = t.row;
            int col = t.col;
            
            if( row == n-1 && col == m-1) return diff;
            
            for( int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if( nrow >=0 && nrow <n && ncol >=0  && ncol <m  ){
                    int newEffort = Math.abs(heights[nrow][ncol] - heights[row][col]);
                    newEffort = Math.max( diff, newEffort);
                    if( dist[nrow][ncol] > newEffort){
                        pq.add( new Tuple(newEffort, nrow, ncol));
                        dist[nrow][ncol] = newEffort;                 
                    }
                                      
                }
            }
        }
        return -1;
        
    }
}
