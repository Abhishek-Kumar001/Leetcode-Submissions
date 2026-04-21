class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 1st way is sort both and find the common elements

        //2nd way is use map, put all the elements of arr1 in map and then treverse arr2 and find the 
        // check that element in mpp

        unordered_map<int, int> mpp;
        for(int x : nums1) mpp[x]++;

        set<int> st;
        for(int x : nums2){
            if(mpp[x]) st.insert(x);
        }

        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
