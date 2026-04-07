class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int carry = 1;
        for(int i=n-1; i>=0; i--){
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            if(sum == 10) carry = 1;
            else carry = 0;
        }

        if(carry == 1){
            vector<int> ans(n+1);
            ans[0] = 1;
            for(int i=1; i<=n; i++){
                ans[i] = digits[i-1];
            }
            return ans;
        }

        return digits;
    }
};
