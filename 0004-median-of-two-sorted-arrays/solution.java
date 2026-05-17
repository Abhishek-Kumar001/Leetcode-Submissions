class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int s = n+m;

        int m1 = -1, m2 = -1;
        if((s & 1) == 1){
            m1= s/2;
            m2= s/2;
        }else{
            m1= s/2-1;
            m2= s/2;
        }

        int i = 0, j=0, cnt = 0;
        int median1 = Integer.MIN_VALUE, median2 = Integer.MIN_VALUE;

        while(i<n && j<m){
            if(median1 != Integer.MIN_VALUE  && median2 != Integer.MIN_VALUE){
                return (double)(median1 + median2)/2;
            }

            if(nums1[i] < nums2[j]){
                if(cnt == m1) median1 = nums1[i];
                if(cnt == m2) median2 = nums1[i];

                cnt++;
                i++;
            }else{
                if(cnt == m1) median1 = nums2[j];
                if(cnt == m2) median2 = nums2[j];

                cnt++;
                j++;
            }
        }

        while(i<n){
            if(median1 != Integer.MIN_VALUE  && median2 != Integer.MIN_VALUE){
                return (double)(median1 + median2)/2;
            }

            if(cnt == m1) median1 = nums1[i];
            if(cnt == m2) median2 = nums1[i];

            cnt++;
            i++;
        }

        while(j<m){
            if(median1 != Integer.MIN_VALUE  && median2 != Integer.MIN_VALUE){
                return (double)(median1 + median2)/2;
            }

            if(cnt == m1) median1 = nums2[j];
            if(cnt == m2) median2 = nums2[j];

            cnt++;
            j++;
        }

        if(median1 != Integer.MIN_VALUE  && median2 != Integer.MIN_VALUE){
            return (double)(median1 + median2)/2;
        }

        return -1;
    }
}
