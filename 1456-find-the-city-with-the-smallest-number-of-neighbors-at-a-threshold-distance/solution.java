class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int dist[][] = new int[n][n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j)  dist[i][i] = 0;
                else dist[i][j] = (int)1e8;
            }
        }

        for(int i=0; i<edges.length; i++){
            int src = edges[i][0];
            int des = edges[i][1];
            int cost = edges[i][2];

            dist[src][des] = cost;
            dist[des][src] = cost;
        }

        for(int via = 0; via < n; via++){
            for(int i=0; i<n; i++){
                if(via == i) continue;
                for(int j=0; j<n; j++){
                    if(i == j) continue;
                    if(dist[i][via] != 1e8 && dist[via][j] != 1e8) 
                       dist[i][j] = Math.min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        
        int ansCity = 0;
        int neighboursCityCnt = n+1;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= neighboursCityCnt){
                ansCity = i;
                neighboursCityCnt = cnt;
            }
        }

        return ansCity;
    }
}
