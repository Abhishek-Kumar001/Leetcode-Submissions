class Pair{
    int first=0,second=0;
    public Pair(int x, int y){
       first = x;  second = y;     
    }
}
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        // yt - code explainer (i have converted cpp -> java)
        int n = nums.size(); 
        List<Pair> al = new ArrayList<Pair>();
        for(int i=0; i<n; i++)
            for(int j=0; j<nums.get(i).size(); j++)
                al.add(new Pair(nums.get(i).get(j), i));

        // Sort the list based on the 'first' value of each Pair
        al.sort((p1, p2) -> Integer.compare(p1.first, p2.first));
        // al = [{0,1}, {4,0}, {5,2}, {9,1}, {10,0}, {12,1}, {15,0}, {18,2}, ...]

        int k = nums.size(); // no of lists
        int start = 0, cnt = 0, minRangeDiff =Integer.MAX_VALUE;
        int[] arr=new int[k], ans = new int[2];

        for(int i=0; i<al.size(); i++){  // treate i as end
            arr[ al.get(i).second ]++;
            if(arr[ al.get(i).second ] == 1)cnt++;  //if this ele is from new list

            if(cnt == k){  // now our range contains ele from all the k list
                int rangeDiff = al.get(i).first -  al.get(start).first;
                if(rangeDiff < minRangeDiff){
                    minRangeDiff = rangeDiff;
                    ans = new int[]{al.get(start).first,  al.get(i).first};
                }

                while(cnt == k){
                    if(arr[al.get(start).second] > 1){
                        arr[al.get(start).second]--;
                        start++;

                        rangeDiff = al.get(i).first -  al.get(start).first;
                        if(rangeDiff < minRangeDiff){
                            minRangeDiff = rangeDiff;
                            ans = new int[]{al.get(start).first,  al.get(i).first};
                        }
                    }
                    else break;                 
                }
            }
        }
        return ans;
    }
}
