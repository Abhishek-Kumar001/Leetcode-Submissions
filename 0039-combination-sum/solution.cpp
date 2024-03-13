class Solution {
public:
    void helper( int i, vector<int> arr, int req, vector<int> temp, vector<vector<int>>         &ans){
        //base case 
        if( i == arr.size()){
            return;
        }
        if( req == 0){
            ans.push_back( temp);
            return ;
        }

        if( arr[i] <= req){
            temp.push_back( arr[i]);
            helper(i, arr, req-arr[i], temp, ans);
            temp.pop_back();
        }

        helper(i+1, arr, req, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n= candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        helper( 0, candidates, target, temp, ans);
        return ans;
        
    }
}; 
