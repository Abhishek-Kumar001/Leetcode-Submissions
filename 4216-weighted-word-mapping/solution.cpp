class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for(string s : words){
            int weight = 0;
            for(char ch : s){
                weight += weights[ch - 'a'];
            }
            char ch = 97 + (25- (weight % 26));
            ans+=ch;
        
        }
        return ans;
    }
};
