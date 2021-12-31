class Solution {
    public int maximumWealth(int[][] accounts) {
        int sum=Integer.MIN_VALUE;
        for(int i=0;i<accounts.length;i++){
            int sumSoFar=0;
            for(int j=0;j<accounts[i].length;j++){
                 sumSoFar+=accounts[i][j];
            }
           if(sum<sumSoFar)
               sum=sumSoFar;
        }
        return sum;
        
    }
}
