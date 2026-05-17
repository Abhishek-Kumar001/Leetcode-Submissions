class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // neet code way optimal (two pointer approach)
        int n = height.size();
        int ans = INT_MIN;
        
        int s=0, l=n-1;
        while( s < l){
            int  mini = min( height[s], height[l]);
            int diff = l-s;
            ans = max( ans, mini*diff);

            if( height[s] < height[l]){
                s++;
            }else{
                l--;
            }
        }
        return ans;
    }
};
