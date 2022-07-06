class Solution {
    public int[] finalPrices(int[] prices) {
      
         /* intution is 1st find next smaller ele of of element if exists then subract that                   smaller  element form that element and store the payable amount in an ans array then               return ans  array    */
       
        //1st find next smaller  element and store it
          int[] next_smaller=new int[prices.length];
          nextSmaller(prices, next_smaller);
        
        //here after nextSmaller() function next_smaller array contains next smaller element
        
        //now fill the ans in the prices array and return this array
        for(int i=0; i<prices.length; i++){
            if(next_smaller[i] != -1){
                prices[i]=prices[i]-next_smaller[i];
            }
        }
        
        return prices;
    }
    public void  nextSmaller(int[]  prices, int[] next_smaller){

        //create an stact  and push -1 in it
        Stack<Integer> stk=new Stack<>();
        stk.push(-1);
        
        //run the for loop and find next smaller ele and store 
        for(int i=prices.length-1; i>=0; i--){
            int val=prices[i];
            
            while(stk.peek() > val){
                stk.pop();
            }
            //out ans is stack ka top()
            next_smaller[i]=stk.peek();
            //put the curr element
            stk.push(val);
        }
    }
}
