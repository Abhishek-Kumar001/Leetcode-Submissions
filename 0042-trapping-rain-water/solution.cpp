class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prevMax(n);
        prevMax[0] = height[0];

        vector<int> nextMax(n);
        nextMax[n-1] = height[n-1];

        // Build prevMax (left max for each index)
        for (int i = 1; i < n; i++) {
            prevMax[i] = max(prevMax[i-1], height[i]);
        }

        // Build nextMax (right max for each index)
        for (int i = n - 2; i >= 0; i--) {
            nextMax[i] = max(nextMax[i + 1], height[i]);
        }

       int waterStore = 0;
       for(int i=1; i<n-1; i++){
           waterStore +=  (min(prevMax[i], nextMax[i]) - height[i]);
       }
       return waterStore;
    }
};
