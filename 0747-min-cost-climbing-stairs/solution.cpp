/*
// #apporoach:1  (RECURSION) -- successful
class Solution {
public:
    int solve(int n, vector<int> &cost){
       //base case
        if(n>=cost.size()){
            return 0;
        }
        
        int ans = cost[n] + min(solve(n+1, cost), solve(n+2, cost));
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = min(solve(0, cost), solve(1, cost) );
        return ans;
    }
};
*/

 
/*
// #APPROACH:2  (RECURSION + MEMOISATION) ---- successfuly submited
class Solution {
public:
    int solve(int n, vector<int> &cost, vector<int> &ans){
       //base case
        if(n>=cost.size()){
            return 0;
        }
        
        if(ans[n] != -1){
            return ans[n];
        }
        
        ans[n] = cost[n] + min(solve(n+1, cost, ans), solve(n+2, cost, ans));
        return ans[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n, -1);
        return  min(solve(0, cost, ans), solve(1, cost, ans) );
       
    }
};
*/


/*
//approach :3  bottom up (tabulation)  sussessfully submited
class Solution {
public:
    int solve(int n, vector<int> &cost){
        vector<int> ans(n, 0);
        ans[0] = cost[0];
        ans[1] = cost[1];
        
        for(int i=2; i<n; i++){
            ans[i] = cost[i] + min(ans[i-1], ans[i-2]);
        }
        return min(ans[n-1], ans[n-2]);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(n, cost);
    }
};
*/



//space optmized
 class Solution {
public:
    int solve(int n, vector<int> &cost){
        
        int prev2 = cost[0];
        int prev1 = cost[1];
        
        for(int i=2; i<n; i++){
            int curr = cost[i] + min(prev2 , prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(n, cost);
    }
};





