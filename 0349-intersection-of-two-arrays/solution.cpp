class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            while (i > 0 && i < n && nums1[i] == nums1[i - 1]) {
                i++;
            
            }
            while (j > 0 && j < m && nums2[j] == nums2[j - 1]) {
                j++;
            }

            if (i < n && j < m) {
                if (nums1[i] == nums2[j]) {
                    ans.push_back(nums1[i]);
                    i++;
                    j++;
                } else if (nums1[i] < nums2[j]) {
                    i++;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};





// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         // Sort both arrays
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());

//         vector<int> ans;
//         int n = nums1.size(), m = nums2.size();
//         int i = 0, j = 0;

//         while (i < n && j < m) {
//             // Skip duplicates in nums1
//             while (i > 0 && i < n && nums1[i] == nums1[i - 1]) {
//                 i++;
//             }
//             // Skip duplicates in nums2
//             while (j > 0 && j < m && nums2[j] == nums2[j - 1]) {
//                 j++;
//             }

//             // Check if indices are still in range after skipping duplicates
//             if (i < n && j < m) {
//                 if (nums1[i] == nums2[j]) {
//                     ans.push_back(nums1[i]);
//                     i++;
//                     j++;
//                 } else if (nums1[i] < nums2[j]) {
//                     i++;
//                 } else {
//                     j++;
//                 }
//             }
//         }

//         return ans;
//     }
// };

