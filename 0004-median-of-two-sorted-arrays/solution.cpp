class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int n3 = n1 + n2;
        int median1 = n3 / 2;
        int median2 = n3 / 2;
        if(n3 % 2 == 0){
            median2 = n3/2 - 1;
        }

        double first = INT_MIN, second = INT_MIN;

        int i=0, j=0, cnt=0;
        while(i < n1 && j <n2){
            if(nums1[i] < nums2[j]){
                if(cnt == median1) first = nums1[i];
                if(cnt == median2) second = nums1[i];
                i++;
            }else{
                if(cnt == median1) first = nums2[j];
                if(cnt == median2) second = nums2[j];
                j++;
            }

            cnt++;

            if(first != INT_MIN && second != INT_MIN) return (first + second)/2;
        }

        while(i < n1){
            if(cnt == median1) first = nums1[i];
            if(cnt == median2) second = nums1[i];
            i++;
            cnt++;

            if(first != INT_MIN && second != INT_MIN) return (first + second)/2;
        }

        while(j < n2){
            if(cnt == median1) first = nums2[j];
            if(cnt == median2) second = nums2[j];
            j++;
            cnt++;

            if(first != INT_MIN && second != INT_MIN) return (first + second)/2;

        }

        return (first + second)/2; 
    }
};
