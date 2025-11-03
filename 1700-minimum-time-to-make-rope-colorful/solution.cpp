class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char lastColor = colors[0];
        int lastColorMinValue = neededTime[0];
        int miniTime = 0;

        for(int i=1; i<colors.size(); i++){
            if(colors[i] == colors[i-1]){
               miniTime += min(neededTime[i], lastColorMinValue);

               // now update the lastColorMinValue 
               lastColorMinValue = max(neededTime[i], lastColorMinValue);
            }
            else{
                lastColor = colors[i];
                lastColorMinValue = neededTime[i];
            }
        }
        return miniTime;
    }
};
