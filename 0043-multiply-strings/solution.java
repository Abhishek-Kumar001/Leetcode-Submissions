class Solution {
    public String multiply(String num1, String num2) {
        // Coding decoding

        //base cases
        int n=num1.length(), m = num2.length();      
        if(num1.equals("0")  || num2.equals("0")) return "0";

        int []ansArr = new int[n+m];
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int product =( num1.charAt(i) - '0') * ( num2.charAt(j) - '0');
                product += ansArr[i+j+1];

                ansArr[i+j+1] = product % 10;
                ansArr[i+j] += product / 10;  // carry  // note there is a + (adding)
            }
        }

        StringBuffer sb = new StringBuffer();
        for(int i=0; i<n+m; i++){
            if(sb.length()== 0  && ansArr[i] == 0)continue;

            sb.append(ansArr[i]);
        }

        return sb.toString();
    }
}
