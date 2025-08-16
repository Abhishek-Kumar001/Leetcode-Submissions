class Solution {
public:
    int reverse(int num){
        int result = 0;
        while(num){
            int rem = num % 10;
            result = result * 10 + rem;

            num = num/ 10;

        }
        return result ;
    }
    int maximum69Number (int num) {
        int reversedNum = reverse(num);
        int result = 0, flag = 0;
        while(reversedNum){
            int rem = reversedNum % 10;
            if(rem == 6  && flag == 0){
                flag = 1;
                result = result * 10 + 9;
            }else {
                result = result*10 + rem;
            }

            reversedNum /=10;

        }
        return result;
    }
};
