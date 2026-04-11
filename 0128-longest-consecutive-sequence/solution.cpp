class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mpp;
        for(int x : nums){
            mpp[x]++;
        }

        int prev = INT_MIN;
        int maxi = 0, count = 0;
        for(auto it : mpp){
            cout<<it.first<<"-"<<it.second<<", ";
            if(prev == INT_MIN){
                count  = 1;
            }else if(it.first == prev+1){
                count++;
            }else{
                count = 1;
            }
            maxi = max(maxi, count);
            prev = it.first;
        }
        return maxi;
    }
};
