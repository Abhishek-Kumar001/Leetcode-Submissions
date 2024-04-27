// import java.util.*;
// class Pair{
//     int v, dist;
//     public Pair(int v, int d){
//         this.v = v; dist = d;
//     }
// }
// class Pair2{
//     int wt , node;
//     public Pair2(int w, int n){
//         wt = w; node = n;
//     }
// }
// class Solution {
//     public int countPaths(int n, int[][] roads) {
//         ArrayList<ArrayList<Pair>> al = new ArrayList<>();
//         for (int i = 0; i <n; i++) {
//             al.add(new ArrayList<Pair>());
//         }

//         for (int[] arr : roads) {
//             al.get(arr[0]).add(new Pair(arr[1], arr[2]));
//             al.get(arr[1]).add(new Pair(arr[0], arr[2]));
//         }
        
//         PriorityQueue<Pair2> pq = new PriorityQueue<Pair2>((x,y)->x.wt - y.wt);
//         pq.add( new Pair2(0, 0));  // (wt, node)

//         int distArr[] = new int[n];
//          Arrays.fill(distArr,Integer.MAX_VALUE);
//         // for( int i=0; i<n; i++) distArr[i] = (int)1e9;
//         distArr[0] = 0;
        
//         int ways[] = new int[n];
//         ways[0] = 1;

//         int mod = (int)Math.pow(10,9)+7;
//         while( !pq.isEmpty()){
//             Pair2 p = pq.remove();
//             int wt = p.wt;
//             int node = p.node;

//             for( Pair p1 : al.get(node)){
//                 int adjNode = p1.v;
//                 int dist = p1.dist;

//                 if( distArr[node] + dist  < distArr[adjNode]){
//                     distArr[adjNode] = distArr[node]  + dist;
//                     pq.add(new Pair2(distArr[adjNode], adjNode));
//                     ways[adjNode] = ways[node];
//                 } 
//                 else if(distArr[node] + dist  == distArr[adjNode] ){
//                     ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
//                 }
//             }
//         }
        
//         return ways[n-1];
//     }
// }






// import java.util.*;

// class Pair {
//     int v, dist;
//     public Pair(int v, int d){
//         this.v = v; 
//         dist = d;
//     }
// }

// class Pair2 {
//     long wt ;
//     int  node;
//     public Pair2(long w, int n){
//         wt = w; 
//         node = n;
//     }
// }

// class Solution {
//     public int countPaths(int n, int[][] roads) {
//         ArrayList<ArrayList<Pair>> al = new ArrayList<>();
//         for (int i = 0; i < n; i++) {
//             al.add(new ArrayList<Pair>());
//         }

//         for (int[] arr : roads) {
//             al.get(arr[0]).add(new Pair(arr[1], arr[2]));
//             al.get(arr[1]).add(new Pair(arr[0], arr[2]));
//         }
        
//         PriorityQueue<Pair2> pq = new PriorityQueue<Pair2>((x, y) ->Long.compare( x.wt, y.wt));
//         pq.add(new Pair2(0, 0));  // (wt, node)

//         long[] distArr = new long[n];
//         Arrays.fill(distArr, Integer.MAX_VALUE);
//         distArr[0] = 0;
        
//         int[] ways = new int[n];
//         ways[0] = 1;

//         int mod = (int)Math.pow(10, 9) + 7;
//         while (!pq.isEmpty()) {
//             Pair2 p = pq.remove();
//             long wt = p.wt;
//             int node = p.node;

//             for (Pair adjPair : al.get(node)) {
//                 int adjNode = adjPair.v;
//                 int adjDist = adjPair.dist;

//                 if (distArr[node] + adjDist < distArr[adjNode]) {
//                     distArr[adjNode] = distArr[node] + adjDist;
//                     pq.add(new Pair2(distArr[adjNode], adjNode));
//                     ways[adjNode] = ways[node];
//                 } else if (distArr[node] + adjDist == distArr[adjNode]) {
//                     ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
//                 }
//             }
//         }
        
//         return ways[n - 1]% mod;
//     }
// }









class Solution {
    public int MOD = (int)(1e9 +7);
    public int countPaths(int n, int[][] roads) {
        ArrayList<ArrayList<Pair>> list = new ArrayList<>();
        for(int i=0;i<n;i++){
            list.add(new ArrayList<>());
        }
        for(int i=0;i<roads.length;i++){
            list.get(roads[i][0]).add(new Pair(roads[i][1],(long) roads[i][2]));
            list.get(roads[i][1]).add(new Pair(roads[i][0], (long)roads[i][2]));
        }
        PriorityQueue<Pair> pq= new PriorityQueue<>((a,b)->Long.compare( a.d,b.d));
        pq.add(new Pair(0,0));
        long[] dist= new long[n];
        Arrays.fill(dist, Long.MAX_VALUE/2);
        dist[0]=0;
        int[] ways = new int[n];
        ways[0]=1;
       // int minD=Integer.MAX_VALUE;
        while(!pq.isEmpty()){
            Pair p = pq.peek();
            int node =p.node;
            long d=p.d;
            pq.poll();
            for(Pair np: list.get(node)){
                int newNode = np.node;
                long newD =np.d;
                if(d+newD<dist[newNode]){
                    ways[newNode]= ways[node];
                    dist[newNode]=d+newD;
                    pq.add(new Pair(newNode,d+newD));
                }
                else if(d+newD==dist[newNode]){
                   ways[newNode]=(ways[newNode]  + ways[node])%MOD;
                }    
            }
        }
        return ways[n-1]%MOD;
    }
}
        
class Pair{
    int node;
    long d;
    Pair(){

    }
    Pair(int node, long d){
        this.node=node;
        this.d=d;
    }
}
