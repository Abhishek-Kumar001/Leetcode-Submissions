class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        for(int i=0; i<n/2; i++) ans[i] = -((n/2)-i);
        if(n % 2 == 0)
          for(int i=n/2; i<n; i++) ans[i] = (i-(n/2))+1;
        else for(int i=n/2; i<n; i++) ans[i] = (i-(n/2)) ;
      
        return ans;
    }
};
