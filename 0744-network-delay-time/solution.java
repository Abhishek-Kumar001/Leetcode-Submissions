class Pair{
    int v, dist;
    public Pair(int v, int d){
        this.v = v; dist = d;
    }
}
class Pair2{
    int time , node;
    public Pair2(int t, int n){
        time = t; node = n;
    }
}
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        ArrayList<ArrayList<Pair>> al = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            al.add(new ArrayList<Pair>());
        }

        for (int[] arr : times) {
            al.get(arr[0]).add(new Pair(arr[1], arr[2]));
        }
        
        PriorityQueue<Pair2> pq = new PriorityQueue<Pair2>((x,y)->x.time - y.time);
        pq.add( new Pair2(0, k));

        int timeArr[] = new int[n+1];
        for( int i=0; i<=n; i++) timeArr[i] = (int)1e9;
        timeArr[k] = 0;

        while( !pq.isEmpty()){
            Pair2 p = pq.remove();
            int time = p.time;
            int node = p.node;

            for( Pair p1 : al.get(node)){
                int adjNode = p1.v;
                int dist = p1.dist;

                if( timeArr[node] + dist  < timeArr[adjNode]){
                    timeArr[adjNode] = timeArr[node]  + dist;
                    pq.add(new Pair2(timeArr[adjNode], adjNode));
                } 
            }
        }
        int maxTime = 0;
        for(int i=1; i<=n; i++){
           if( timeArr[i] == (int)1e9) return -1;
           maxTime = Math.max(maxTime, timeArr[i]);
        }
        return maxTime;
    }
}


