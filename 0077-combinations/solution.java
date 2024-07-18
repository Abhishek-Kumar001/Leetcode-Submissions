class Solution {
    public List<List<Integer>> combine(int n, int k) {
          //@ my code 100%
        List<List<Integer>> ansList = new ArrayList<>();
        List<Integer> temp = new ArrayList<Integer>();
        
        combination(1,n,k,temp, ansList);
       
        return ansList;
    }
    public void combination(int i, int n, int k, List<Integer> temp, List<List<Integer>> ansList){

        //base case
        if(k == 0){
             // ansList.add(temp);   // this is wrong
            ansList.add(new ArrayList<>(temp));
           
            return ;
        }
        if(i>n) return ;
        if(n-i+2 < k) return ;  //if we have less elements than what length list we 
                             //we need so it is useLess to proced aheade

        // else we have two choices either tate i or not
        temp.add(i);
        combination(i+1, n, k-1, temp, ansList);
        temp.remove(temp.size()-1);
        combination(i+1, n, k, temp, ansList);
       

    }
}
