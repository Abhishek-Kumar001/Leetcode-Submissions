class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mpp;
        for(int no : nums){
            if(no > 0) mpp[no]++;
        }

        int cnt = 1;
        for(auto it : mpp){
            if(it.first != cnt) return cnt;
            cnt++;
        }
        return cnt;
    }
};
