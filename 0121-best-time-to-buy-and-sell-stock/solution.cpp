class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int miniSoFar = prices[0];

        for(int i=1; i<prices.size(); i++){
            maxProfit = max(maxProfit, prices[i] - miniSoFar);

            miniSoFar = min(miniSoFar, prices[i]);
        }
        return maxProfit;
    }
};
