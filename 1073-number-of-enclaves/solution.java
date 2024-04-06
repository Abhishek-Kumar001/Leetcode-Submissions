class Pair{
    int first, second;
    public Pair(int f, int s){
        first = f;
        second = s;
    }
}

class Solution {
    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int [][]visited = new int[n][m];
        for( int i=0; i<n; i++){
            for( int j=0; j<m; j++){
                if( i==0 || j==0 || i == n-1 || j == m-1){
                    if( grid[i][j] == 1  &&  visited[i][j] == 0)
                         markVisited(i, j, visited, grid, n, m);
                }
            }
        }

        int cnt = 0;
        for( int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( grid[i][j] == 1  && visited[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    public void markVisited(int i, int j, int [][]visited, int[][] arr, int n,                                          int m){

        visited[i][j] = 1;
        //queue<pair<int, int>> q;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(i, j));


        int drow[] = { 0, +1, 0,-1};
        int dcol[] = {+1, 0, -1, 0};
        while( !q.isEmpty()){
            Pair p = q.remove();
            int row = p.first;
            int col = p.second;
            //q.remove();

            for( int k=0; k<4; k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if( nrow >=0 && nrow<n && ncol >=0 && ncol <m && 
                           visited[nrow][ncol] == 0  && arr[nrow][ncol] == 1 ){

                     visited[nrow][ncol] = 1;
                     q.add(new Pair(nrow,ncol));
                }
            }
        }
    }
}
