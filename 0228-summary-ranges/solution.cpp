class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        string s = to_string(nums[0]);
        ans.push_back(s);

        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == prev+1){
                prev++;
            }else{
                if(stoi(ans.back()) == nums[i-1]){
                    ans.push_back(to_string(nums[i]));
                }else{
                    ans[ans.size()-1] = ans.back() + "->" + to_string(prev);
                    ans.push_back(to_string(nums[i]));
                }
                prev = nums[i];
            }

            if(i == nums.size()-1){
                if(stoi(ans.back()) == nums[i]){
                    // do nothing
                }else{
                    ans[ans.size()-1] = ans.back() + "->" + to_string(nums[i]);
                }
            }
        }
        return ans;
    }
};
