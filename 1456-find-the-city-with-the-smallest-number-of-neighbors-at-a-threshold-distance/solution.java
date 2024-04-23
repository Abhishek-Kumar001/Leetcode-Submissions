class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int dist[][] = new int[n][n];
        for( int i=0; i<n; i++){
           for(int j=0; j<n; j++){
               dist[i][j] = Integer.MAX_VALUE;
               if( i == j) dist[i][j] = 0;
           }
        }
        
        int m = edges.length;
        for(int i=0; i<m; i++){
            int u= edges[i][0];
            int v= edges[i][1];
            int wt = edges[i][2];
            
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        
        // Floyd-Warshall algorithm to calculate all pair shortest paths
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                   if( via == i) continue;
                   if(dist[i][via] != Integer.MAX_VALUE  && dist[via][j] != Integer.MAX_VALUE){
                       dist[i][j] = Math.min(dist[i][j], (dist[i][via] + dist[via][j]) );
                   }
                }
            }
        }
        
        int ansCity = n;
        int minNoOfNeighbours = Integer.MAX_VALUE;
        for(int i=0; i<n; i++){
            int noOfNeighbours = 0;
            for(int j=0; j<n; j++){
               if(dist[i][j] != Integer.MAX_VALUE  && dist[i][j] <= distanceThreshold){
                   noOfNeighbours++;
               }
            }
            if( noOfNeighbours <= minNoOfNeighbours){
                minNoOfNeighbours = noOfNeighbours;
                ansCity = i;
            }
        }
        return ansCity;
    }
}
