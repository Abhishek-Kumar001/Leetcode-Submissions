class Pair{
    int first =0, second =0;
    public Pair(int x, int y){
        first = x; second = y;
    }

    @Override
    public String toString() {
        return "(" + first + ", " + second + ")";
    }
}

class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>((a,b)-> b.first - a.first);

        for(int i=0; i<arr.length; i++){
            if(i<k){
                pq.add(new Pair(Math.abs(x-arr[i]),  arr[i]));
            }
            else{
                int diff= Math.abs(x-arr[i]);
                if(pq.peek().first > diff){
                    pq.poll();
                    pq.add(new Pair(diff, arr[i]));
                }
            }
        }

        List<Integer> al = new ArrayList<Integer>();
        while(pq.size() >= 1){
            int ele = pq.peek().second;
            pq.poll();

            al.add(ele);
        }
        Collections.sort(al);
        return al;
    }
}
