class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount+1, 0);
        for( int amt =0; amt<=amount; amt++){
            if( amt % coins[0] == 0){
                prev[amt] = 1;
            }
        }
        
        for( int row=1; row<coins.size(); row++){
            vector<int> curr(amount+1, 0);
            for( int amt=0; amt<=amount; amt++){
                int notTake = prev[amt];
                int take = 0;
                if( coins[row] <= amt){
                    take = curr[amt - coins[row]];
                }
                
                curr[amt] = take + notTake;
                
            }
            prev = curr;
        }
        return prev[amount];
    }
};
