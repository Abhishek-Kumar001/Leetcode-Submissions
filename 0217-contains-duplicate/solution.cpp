class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int x : nums){
            if(mpp[x] == 0) mpp[x]++;
            else return true;
        }
        return false;
    }
};
