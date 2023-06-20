class Solution {
public:
    
    void helper(int index, int require , vector<int>&  arr,  vector<int>&  temp, vector<vector<int>> &ansVector ){
        //base case1
        if(index >= arr.size()){
            if(require == 0){
                ansVector.push_back(temp);
            }
            return;
        }
        // base case2
        if(require == 0){
            ansVector.push_back(temp);
           // if(temp.size() > 1)
            //  temp.pop_back();
            return;
        }
        if(arr[index] <= require){
            temp.push_back(arr[index]);
            helper(index, require-arr[index], arr, temp, ansVector);
            temp.pop_back();
        }
        helper(index +1, require, arr, temp, ansVector);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ansVector;
        vector<int> temp;
        helper(0, target,candidates, temp,  ansVector);

        return ansVector;
    }
};
