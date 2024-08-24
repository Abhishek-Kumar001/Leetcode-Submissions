class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size(), m = nums2.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(nums1[i] == nums2[j]){
                    int cnt = 1;
                    int ii=i+1, jj= j+1;
                    while(ii<n && jj<m && nums1[ii] == nums2[jj]){
                        cnt++;
                        ii++; jj++;
                    }
                    maxLen = max(maxLen, cnt);
                }
            }
        }
        return maxLen;
    }
};
