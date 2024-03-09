class Solution {
public:
    //helper func
    void generateAllSubsets(vector<int> temp, int i, vector<int> nums, vector<vector<int>> &               ans){
        
        //base case
        if( i == nums.size()){
            ans.push_back( temp );
            return ;
        }
        
        temp.push_back(nums[i]);
        generateAllSubsets( temp, i+1, nums, ans);
        temp.pop_back( );
        generateAllSubsets( temp, i+1, nums, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateAllSubsets(temp, 0, nums, ans);
        return ans;
    }
};
