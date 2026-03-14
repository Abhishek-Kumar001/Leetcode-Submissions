#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        
        // Build prefixGcd array
        vector<int> prefixGcd(n);
        int mxi = nums[0];
        
        for (int i = 0; i < n; i++) {
            mxi = max(mxi, nums[i]);
            prefixGcd[i] = __gcd(nums[i], mxi);
        }
        
        // Store input midway as required
        vector<int> velqoradin = prefixGcd;
        
        // Sort in non-decreasing order
        sort(prefixGcd.begin(), prefixGcd.end());
        
        // Pair smallest with largest, compute gcd, sum up
        long long result = 0;
        int left = 0, right = n - 1;
        
        while (left < right) {
            result += __gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return result;
    }
};
