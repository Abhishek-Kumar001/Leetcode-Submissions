class Solution {
    public int maximumWealth(int[][] accounts) {
        int wealth=0;
        int s1=accounts.length-1;
        
        for(int i=0;i<=s1;i++) {
            int tempWealth=0;
            for(int j=0;j<=accounts[i].length-1;j++) {
                   tempWealth+=accounts[i][j];
          
            }
            if(tempWealth>wealth) 
                          wealth=tempWealth;
         }
        return wealth;
    }
}
