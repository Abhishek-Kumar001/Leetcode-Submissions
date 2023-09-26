class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> maxNext(n);
        vector<int> maxPrev(n);
       
        int maxi = height[n-1];
        for(int i=n-1; i>=0; i--){
           maxi = max( maxi, height[i]);
           maxNext[i] = maxi;
        }

        int maxi2 = height[0];
        for(int i=0; i<n; i++){
            maxi2 = max( maxi2, height[i]);
            maxPrev[i]= maxi2;
        }

        int ans =0;
        for(int i=1; i<n; i++){
           int mini = min( maxNext[i], maxPrev[i]);
           ans+= mini - height[i];
        }
        return ans;
    }
};
