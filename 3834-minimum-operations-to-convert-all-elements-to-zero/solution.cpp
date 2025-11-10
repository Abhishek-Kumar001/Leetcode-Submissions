#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        vector<int> st; // will use as stack, monotonic increasing

        for (int x : nums) {
            if (x == 0) {
                // zero splits the array: clear active values
                st.clear();
                continue;
            }
            // pop values greater than x
            while (!st.empty() && st.back() > x) st.pop_back();
            // if top equals x, nothing new
            if (!st.empty() && st.back() == x) {
                // reuse existing operation
                continue;
            }
            // else we need a new operation for this value x
            st.push_back(x);
            ++ops;
        }
        return ops;
    }
};

