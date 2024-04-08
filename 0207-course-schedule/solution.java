class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList< ArrayList<Integer>> adjList = new ArrayList<>();
        for( int i=0; i<numCourses; i++){
            adjList.add( new ArrayList<Integer>());
        }
        
        int indegree[] = new int[numCourses];
        for( int i=0; i<prerequisites.length; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adjList.get(v).add(u);
            indegree[u]++;
        }    
        
        
        Queue<Integer> q = new LinkedList<Integer>();
        for(int i=0; i<numCourses; i++){
            if( indegree[i] == 0){
                q.add( i);
            }
        }
        
        
        int cnt=0;
        int ans[] = new int[numCourses];
        int k=0;
        while( !q.isEmpty()){
            int front = q.remove();
            cnt++;
            ans[k++] = front;
            
            for( int neighbour : adjList.get(front) ){ 
                 indegree[neighbour]--;
                if( indegree[neighbour] == 0){
                    q.add( neighbour );
                }
            }
        }
        if( cnt != numCourses) return false;
        return true;
    }
}
