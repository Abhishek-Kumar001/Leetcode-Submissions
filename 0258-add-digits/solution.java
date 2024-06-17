class Solution {
    public int addDigits(int num) {
      // this check is imp b/c Math.log10(0) will gives us -invinity
        //if( num == 0) return 0;
        while( Math.log10(num) >= 1 ){
            int sumNo = 0;
            while(num > 0){
                int rem = num%10;
                sumNo+=rem;
                num/=10;
            }
            num = sumNo;
        }
        return num;
        
    }
}
