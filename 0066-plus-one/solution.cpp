class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        int carry = 1;
        for(int i = n-1; i >= 0; i--){
           int sum = carry + v[i];
           carry = sum / 10;
           sum = sum % 10;          
           v[i] = sum;
        }
        if( carry == 1){
            vector<int> newVec(n+1, 0);
            newVec[0] = 1;          
            return newVec;
        }
        return v;
    }
};
