/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1, right=0, index=0;
        while(left>=0 && right<n){
            if(nums1[left]<=nums2[right]){
                left--;
            }
            else{
                swap(nums1[left],nums2[right]);
                right++;
                left--;
            }

        }
        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(), nums2.end());
        
        for(int i=0; i<n; i++){
            nums1[m++] = nums2[i];

        }

    }
};

*/

// method 2 (bruit force)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        // storing vlaues of nums1 & nums2 in temp vector in sorted order
        int left=0, right=0;
        while(left < m && right<n){
            if(nums1[left]<=nums2[right]){
                temp.push_back(nums1[left]);
                left++;
            }
            else{
               temp.push_back(nums2[right]);
                right++;
            }

        }
        
        // if still nums1 me data bacha hua hai to temp vector me dal de
        for(left; left<m; left++){
            temp.push_back(nums1[left]);
        }
        
        // if still nums2 me values bacha hua hai to temp vector me dal de
        for(right ; right<n; right++){
            temp.push_back(nums2[right]);
        }
        
        
        // now finnaly sorted array of nums1 me coppy kare
        for(int i=0; i<temp.size(); i++){
            nums1[i] = temp[i];
        }
        

    }
};
