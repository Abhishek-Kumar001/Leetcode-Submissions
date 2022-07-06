class Solution {
    public List<String> buildArray(int[] target, int n) {
        
        ArrayList<String> al=new ArrayList<>();
        
        int k=0;
        for(int i=1; i<=n; i++){
            if(target[k] == i){
                al.add("Push");
                k++;
            }
            else{
                al.add("Push");
                al.add("Pop");
            }
            
            if(k==target.length){
                return al;
            }
        }
    
        return al;
    }
}
