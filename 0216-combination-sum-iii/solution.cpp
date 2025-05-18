class Solution {
    void helper(int val, int k, int req, vector<int> temp, vector<vector<int>> &ans){
        
       
        //base case 1: we have k nos in temp vector
        if(temp.size() == k ){
            if( req == 0){
                ans.push_back(temp);
                return;
            }
            return ;            
        }
        // base case 2
        if(val > 9) return ;

        //base case 3: val > req;
        if(val > req) return ;


        // now we have 2 choices, take or not Take 
        // take it
        temp.push_back(val);
        helper(val+1, k, req-val, temp, ans);
        temp.pop_back();

        // not take option
        helper(val+1, k, req, temp, ans);

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1, k, n, temp, ans);

        return ans;
    }
};
