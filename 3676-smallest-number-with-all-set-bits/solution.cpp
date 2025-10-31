class Solution {
public:
    int smallestNumber(int n) {
        int bits = 0;
        int temp = n;
        
        // Count bits in n
        while (temp > 0) {
            bits++;
            temp >>= 1;
        }
        
        // Create all 1s number with that many bits
        int ans = (1 << bits) - 1;
        
        return ans;
    }
};

