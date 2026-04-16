class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans;
        for(int i=0; i<n-1; i++){
           if(nums[i] == nums[i+1]) i++;
           else{
              ans.push_back(nums[i]);
              if(ans.size() == 2) return ans;
           }
        }
        if(ans.size() == 1) ans.push_back(nums[n-1]);
        return ans;
    }
};
