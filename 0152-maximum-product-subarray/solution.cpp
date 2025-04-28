#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0]; // handle negative numbers too
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long tempProduct = 1; // reset for each new subarray start
            for (int j = i; j < n; j++) {
                tempProduct *= nums[j]; // multiply nums[j], not nums[i]
                maxProduct = max(maxProduct, (int)tempProduct);
            }
        }

        return maxProduct;
    }
};

