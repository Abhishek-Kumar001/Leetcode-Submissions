                    // %%%%%%$$$$$$$$$@@@@@@@@ WRONG ANS AA RHA HAI , STRIVER KA CODE HI
                // HI CHAL RHA HA MERA NAHI -- SEE BELLOW
// class Pair{
//     int v, price;
    
//     public Pair(int v, int p ){
//         this.v = v;
//         price = p;
//     }
// }
// class Pair2{
//     int steps, node;
//     public Pair2(int s, int n){
//         steps = s;
//         node = n;
//     }
// }
// class Solution {
//     public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
//         ArrayList<ArrayList<Pair>> al = new ArrayList<>();
//         for( int i=0; i<n; i++){
//            al.add(new ArrayList<Pair>());
//         }
        
//         for(int arr[]: flights){
//             al.get(arr[0]).add(new Pair(arr[1], arr[2]));
//         }
        
//         PriorityQueue<Pair2> pq  = new  PriorityQueue<Pair2>((x, y)->x.steps - y.steps);
//         pq.add(new Pair2(0,src));  // (step, node)
        
//         int dist[] = new int[n];
//         for( int i=0; i<n; i++) dist[i] = (int)1e9;
//         dist[src] = 0;
        
//         while( !pq.isEmpty()){
//             Pair2 p = pq.remove();
//             int steps = p.steps;
//             int node = p.node;
            
//             if( steps > k) break;
            
//             for( Pair p1 : al.get(node)){
//                 int adjNode = p1.v;
//                 int price = p1.price;
                
//                 if( dist[node] + price < dist[adjNode]    && steps<=k){    
//                     dist[adjNode] = dist[node] + price;
//                     pq.add(new Pair2(steps +1, adjNode));
//                 }
//             }
//         }
        
//         if( dist[ dst] != (int)(1e9)) return dist[dst];
//         return -1;
//     }
// }



         // $$$$$ @@@@@@@ STRIVER  CODE HI SUBMIT HO RHA HAI  tuple wala     
class Pair {
    int v, price;

    public Pair(int v, int p) {
        this.v = v;
        price = p;
    }
}

class Tuple {
    int steps, node, cost;

    public Tuple(int s, int n, int c) {
        steps = s;
        node = n; cost = c;
    }
}

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        ArrayList<ArrayList<Pair>> al = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            al.add(new ArrayList<Pair>());
        }

        for (int[] arr : flights) {
            al.get(arr[0]).add(new Pair(arr[1], arr[2]));
        }

        PriorityQueue<Tuple> pq = new PriorityQueue<Tuple>((x, y) -> x.steps - y.steps);
        pq.add(new Tuple(0, src, 0));  // (step, node, cost)

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        while (!pq.isEmpty()) {
            Tuple t = pq.poll();
            int steps = t.steps;
            int node = t.node;
            int cost = t.cost;

            if (steps > k) continue;

            for (Pair p1 : al.get(node)) {
                int adjNode = p1.v;
                int price = p1.price;

                if (cost + price < dist[adjNode]) {
                    dist[adjNode] = cost + price;
                    pq.add(new Tuple(steps + 1, adjNode, cost+price));
                }
            }
        }

        return dist[dst] != Integer.MAX_VALUE ? dist[dst] : -1;
    }
}

