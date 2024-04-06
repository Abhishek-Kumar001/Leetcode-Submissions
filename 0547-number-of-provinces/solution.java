
class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n=isConnected.length;
        int m = isConnected[0].length;
        
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        for(int i=0; i<n; i++){
            adjList.add(new ArrayList<Integer>());
        }
        
        for( int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( isConnected[i][j] == 1){
                   adjList.get(i).add(j);
                   adjList.get(j).add(i);
                }
            }
        }
        
        int visited[]= new int[n];
        int cnt=0;
        
        
        for(int i=0; i<n; i++){
           if( visited[i] == 0){
               cnt++;
               bfs(i, visited, isConnected, adjList);
           }
        }
        return cnt;
    }
    
    
    public void bfs(int nodee, int []visited, int[][]  isConnected,                                                                  ArrayList<ArrayList<Integer>> adjList){
       
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(nodee);
        visited[nodee] = 1;
        
        while( q.size() >= 1){
            int node = q.remove();
            
            for (int neigh : adjList.get(node)) {
                if ( visited[neigh] == 0) {
                    q.add(neigh);
                    visited[neigh] = 1;
                }
            }
        }
    }
}

