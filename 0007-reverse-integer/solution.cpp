class Solution {
public:
    int reverse(int x) {
        long long no = x;
        int reverse = 0;
        while(no){
            int rem = no % 10;
            no = no / 10;
            if(reverse > INT_MAX / 10 || reverse < INT_MIN / 10) return 0;

            reverse= reverse*10 + rem;
        }
        return reverse;
    }
};
