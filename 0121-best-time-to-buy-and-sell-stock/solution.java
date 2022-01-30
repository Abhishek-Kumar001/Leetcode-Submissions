class Solution {
    public int maxProfit(int[] prices) {
        int i=0;
        int cp=prices[0];
        int sp=prices[0];
        int max_profit=0;

        for(i=1;i<prices.length;i++){
         if(prices[i]>cp && prices[i]>sp){
             sp=prices[i];
             if(sp-cp>max_profit)
                max_profit=sp-cp;
         }
         else if(prices[i]<cp){
            // for(int  j=i+1;j<prices.length;j++){
              //   if(prices[j]-prices[i]>max_profit){
                     cp=prices[i];
                    sp=prices[i];  
                     //max_profit=sp-cp;
                    // i=j;
                  //   break;
                         
                 //}
            // }
         }
        }
        return max_profit;
    }
}
