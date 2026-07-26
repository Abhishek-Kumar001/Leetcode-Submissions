class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();

        int totalLen = s1 + s2;
        int m1Ind = totalLen / 2;
        int m2Ind = totalLen / 2;

        if (totalLen % 2 == 0)
            m2Ind = m1Ind - 1;

        double m1 = INT_MIN;
        double m2 = INT_MIN;

        int i = 0, j = 0, cnt = -1;

        while (i < s1 && j < s2) {
            cnt++;
            if (nums1[i] < nums2[j]) {
                if (cnt == m1Ind)
                    m1 = nums1[i];
                if (cnt == m2Ind)
                    m2 = nums1[i];
                i++;
            } else {
                if (cnt == m1Ind)
                    m1 = nums2[j];
                if (cnt == m2Ind)
                    m2 = nums2[j];
                j++;
            }

            if (m1 != INT_MIN && m2 != INT_MIN)
                return (m1 + m2) / 2;
        }

        while (i < s1) {
            cnt++;
            if (cnt == m1Ind)
                m1 = nums1[i];
            if (cnt == m2Ind)
                m2 = nums1[i];
            i++;

            if (m1 != INT_MIN && m2 != INT_MIN)
                return (m1 + m2) / 2;
        }

        while (j < s2) {
            cnt++;
            if (cnt == m1Ind)
                m1 = nums2[j];
            if (cnt == m2Ind)
                m2 = nums2[j];
            j++;

            if (m1 != INT_MIN && m2 != INT_MIN)
                return (m1 + m2) / 2;
        }

        return -1; // just for the compiler
    }
};
