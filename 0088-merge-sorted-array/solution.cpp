class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // bruit force
        // TC - O(klogk); where k = m+n;
        // SC - O(0)

        // put all the elements of nums2 in nums1 and sort the nums1;
        int j=0;
        for(int i=m; i<m+n; i++){
            nums1[i] = nums2[j++];
        }

        // sorting takes nlogn  where n is the totel size of array
        sort(nums1.begin(), nums1.end());
    }
};
