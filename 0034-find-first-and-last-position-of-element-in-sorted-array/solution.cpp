class Solution {
public:
    vector<int> searchRange(vector<int>& v, int x) {
        // code here
        
        vector<int> ans(2,-1);
        // base case 
        if(v.empty()){
            return ans;
        }
        
        ans[0] = findOccerence(true, v, x);
        if(ans[0] == -1){
            return ans;
        }
        else{
            ans[1] = findOccerence(false, v, x);
        }
        
        return ans;
    }
    int findOccerence(bool isfirst, vector<int> &v, int x){
        int ans =-1;
        int start = 0; 
        int end = v.size()-1;
        
        while( start <= end){
          int mid = start + (end- start)/2;
          
          if( v[mid] == x){
              // this may be the potiential ans 
              ans = mid;
              if( isfirst)
                end = mid-1;
              else
                start = mid+1;
          }
          else if( v[mid] < x){
              start = mid+1;
          }
          else{
              end = mid-1;
          }
        }
        return ans;
    }
};
