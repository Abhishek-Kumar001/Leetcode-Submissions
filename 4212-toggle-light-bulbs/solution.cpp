class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int, bool> bulbCondition;

        for(int x : bulbs){
            if(bulbCondition[x]) bulbCondition[x] = !bulbCondition[x];
            else bulbCondition[x] = true;
        }

        vector<int> ans;
        for(auto &it : bulbCondition){
            if(it.second) ans.push_back(it.first);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
