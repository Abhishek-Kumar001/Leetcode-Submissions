/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // my  bruit force
        int n = height.size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int mini = min( height[i], height[j]);
                int diff = j-i;
                ans = max( ans, mini*diff);
            }
        }
        return ans;
    }
};
*/

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
