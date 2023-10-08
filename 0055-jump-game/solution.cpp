/*
class Solution {
private:
   bool helper(int ind, int n, vector<int> &nums){
       // base case 
       if( ind == n-1) return true;

       bool reached  = false;
       for(int i = ind+1; i<=ind+nums[ind]; i++) {
            reached = helper(i, n, nums);
            if( reached ) return true;
       }
       return reached;
   }
public:
    bool canJump(vector<int>& nums) {
        // my code
        int n = nums.size();

        return helper(0, n, nums);
    }
};
*/




/*
// my code // rec + memo
class Solution {
private:
   bool helper(int ind, int n, vector<int> &nums, vector<int> &dp){
       // base case 
       if( ind == n-1) return true;

       if(dp[ind] != -1) return dp[ind];

       bool reached  = false;
       for(int i = ind+1; i<=ind+nums[ind]; i++) {
            reached = helper(i, n, nums, dp);
            if( reached ) return true;
       }
       return dp[ind] = reached;
   }
public:
    bool canJump(vector<int>& nums) {
        // my code // rec + memo
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, n, nums, dp);
    }
};
*/



// O(N) SOLUTION GREEDY APP
class Solution {

public:
    bool canJump(vector<int>& nums) {
        // TECHDOSE APP GREEDY APP
        int n= nums.size();
        if( n > 1 && nums[0] == 0) return false;

        int reachable = 0;
        for(int i=0; i<n; i++){
            if( i > reachable){
                return false;
            }
             
            reachable = max( reachable, i+nums[i]);

            if( reachable == n-1) return true;

        }
        return true;// this is only for compiler our ans we be return in for loop definitely
    }
};





