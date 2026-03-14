class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp1;
        unordered_map<int, int> mpp2;

        int n = nums1.size();
        for(int i =0; i<n; i++){
            mpp1[nums1[i]]++;
            mpp2[nums2[i]]++;
        }

        for(int i=0; i<n; i++){
            int cntInNums1 = mpp1[nums1[i]];
            int cntInNums2 = mpp2[nums1[i]];

            int mini = min(cntInNums1, cntInNums2);
            mpp1[nums1[i]]-= mini;
            mpp2[nums1[i]]-= mini;
        }

        int cnt = 0;
        for(auto entry : mpp1){
            if( entry.second != 0 && entry.second % 2 != 0){
                // cout<<"1st";
                // cout<<"entry = "<<entry.first<<"-"<<entry.second;
                return -1;
            } 
            cnt+=entry.second;
        }

        int cnt2 = 0;
        for(auto entry : mpp2){
            if( entry.second != 0 && entry.second % 2 != 0){
                // cout<<"2nd";
                // cout<<"entry = "<<entry.first<<"-"<<entry.second;
                return -1;
            } 
            cnt2+=entry.second;
        }

        if(cnt != cnt2){
            // cout<<"count = "<<cnt<<"-"<<cnt2;
            return -1;
        } 
        return cnt/2;
    }
};
