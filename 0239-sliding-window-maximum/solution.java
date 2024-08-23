class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        // tech dose code  but this time i have not copy (i have learn and 100% understood, then i have coded)
        Deque<Pair> dq = new LinkedList<>();
        int n = nums.length;
        int []ans = new int[n-k+1];
        int ind = 0;
        for(int i=0; i<n; i++){
            if(dq.size() >= 1 && dq.getFirst().second <= i-k ){
                dq.pollFirst();
            }

            while(dq.size() >= 1 && dq.getLast().first < nums[i]){
                dq.pollLast();
            }

            dq.addLast(new Pair(nums[i], i));

            if(i+1 >= k){
                ans[ind++] = dq.getFirst().first;
            }
        }
        return ans;
    }
}
class Pair{
    int first = 0, second = 0;
    Pair(int f, int s){
        first = f;
        second = s;
    }
}
