// class Solution {
//     public String multiply(String num1, String num2) {
//         // Coding decoding

//         //base case           
//         if(num1.equals("0")  || num2.equals("0")) return "0";
//         if(num1.equals("1")) return num2;
//         if(num2.equals("1")) return num1;

//         int n=num1.length(), m = num2.length();  
//         int []ansArr = new int[n+m];
//         for(int i=n-1; i>=0; i--){
//             for(int j=m-1; j>=0; j--){
//                 int product =( num1.charAt(i) - '0') * ( num2.charAt(j) - '0');
//                 product += ansArr[i+j+1];

//                 ansArr[i+j+1] = product % 10;
//                 ansArr[i+j] += product / 10;  // carry  // note there is a + (adding)
//             }
//         }

//         StringBuffer sb = new StringBuffer();
//         for(int r : ansArr){
//             if(sb.length()== 0  && r == 0)continue;

//             sb.append(r);
//         }
//         return sb.toString();
//     }
// }



class Solution {
    public String multiply(String num1, String num2) {
        // Coding decoding
        
        //base case 
        if(num1.length() == 1  && num1.equals("0"))return "0";
        if(num2.length() == 1  && num2.equals("0"))return "0";

        if(num1.length() == 1 && num1.equals("1"))return  num2;
        if(num2.length() == 1 && num2.equals("1"))return  num1;

        int n= num1.length(), m= num2.length();
        int nm = n+m;
        int []ans = new int[nm];

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int no1 = num1.charAt(i)-'0';
                int no2 = num2.charAt(j)-'0';

                int result = no1 * no2;
                result += ans[i+j+1];
                ans[i+j+1] =  result % 10;
                result = result/10;
                ans[i+j] += result;
            }
        }

        StringBuffer sb = new StringBuffer();
        for(int i=0; i<nm; i++){
            if(sb.length() == 0 && ans[i]== 0){
                //skip
            }else{
                sb.append(ans[i]);
            }
        }

        return sb.toString();
    }
}
