class Solution {
    public int[] getNoZeroIntegers(int n) {
        int []ans = new int[2];

        for(int i=1; i<=n; i++){
            if(!isthisNoContainsZero(i)){
                int secNo = n-i;
                if(!isthisNoContainsZero(secNo)){
                    ans[0] = i;
                    ans[1] = secNo;
                    return ans;
                }
            }
        }
        // it is mention in question that "there is at least one valid solution" so this will 
        // never execute so no need to care
        return ans;
    }

    public boolean isthisNoContainsZero(int no){
        while(no > 0){
            if(no % 10 == 0) return true;
            no = no / 10;
        }
        return false;
    }
}
