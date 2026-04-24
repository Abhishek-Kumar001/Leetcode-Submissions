class Solution {
public:
    int n;
    unordered_map<int, int> mpp;
    int dp[2001][2001];

    bool solve(vector<int>& stones, int curr_stone_ind, int prevJump){
        if(curr_stone_ind == n-1) return true;

        if( dp[curr_stone_ind][prevJump] != -1) return  dp[curr_stone_ind][prevJump];
        
        bool result = false;
        for(int i=-1; i<=1; i++){
            int nextJump = prevJump + i;

            if(nextJump > 0){
                int nextStone = stones[curr_stone_ind] + nextJump;
                if(mpp[nextStone]){
                    result = result || solve(stones, mpp[nextStone], nextJump);
                }
            }
        } 
        return dp[curr_stone_ind][prevJump] = result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1] != 1) return false;

        memset(dp, -1, sizeof(dp));

        for(int i=0; i<n; i++) mpp[stones[i]] = i;

        return  solve(stones, 0, 0);
    }
};
