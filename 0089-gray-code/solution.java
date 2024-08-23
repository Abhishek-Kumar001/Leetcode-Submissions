class Solution {
    public List<Integer> grayCode(int n) {
        // Coding Decoded app yt
        ArrayList<Integer> al = new ArrayList<Integer>();
        al.add(0);
        al.add(1);  //handle up to n=1;
        
        int pow = 1;
        for(int i=2; i<=n; i++){
            pow = pow*2;

            for(int j=al.size()-1; j>=0; j--){
                al.add(al.get(j) + pow);
            }
        }
        return al;
        
    }
}
