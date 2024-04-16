class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n= nums1.length, m = nums2.length;
        int size = (n+m);

        int mid1, mid2;
        if( size % 2 == 0){
            mid1 = (size/2)-1;
            mid2 = size/2;
        }
        else{
            mid1 = size/2;
            mid2 = size/2;
        }

        int i=0, j=0, k=0;
        double val1 = Integer.MAX_VALUE, val2 = Integer.MAX_VALUE;  // int-max b/c to our
        // array contains -ve values also

        while( i<n && j<m){

            if( nums1[i] < nums2[j]){
                if( k== mid1) val1 = nums1[i];
                if( k == mid2) val2 = nums1[i];

                i++;
            }else{
                if( k== mid1) val1 = nums2[j];
                if( k == mid2) val2 = nums2[j];

                j++;
            }

            k++;

            if( val1 != Integer.MAX_VALUE && val2 != Integer.MAX_VALUE){
                return (val1 + val2)/2;
            }

        }

        while( i < n){
            if( k== mid1) val1 = nums1[i];
            if( k == mid2) val2 = nums1[i];

            i++; k++;  // k ko v increase kare // **** vvvi****

            if( val1 != Integer.MAX_VALUE && val2 != Integer.MAX_VALUE){
                return (val1 + val2)/2;
            }
        }

        while( j<m){
            if( k== mid1) val1 = nums2[j];
            if( k == mid2) val2 = nums2[j];

            j++;  k++;  // k ko v increase kare // **** vvvi****

            if( val1 != Integer.MAX_VALUE && val2 != Integer.MAX_VALUE){
                return (val1 + val2)/2;
            }
        }
        
        
        // vvvvi b/c if one arrys is empty the this will  execute
        // eg:- nums2= [], nums2=[2,3]; 
        // if( val1 != Integer.MAX_VALUE && val2 != Integer.MAX_VALUE){
        //         return (val1 + val2)/2;
        // }

        return 1.0;  // it is never going to execute
    }
}
