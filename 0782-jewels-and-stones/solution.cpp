class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char, int> mpp;
        for(char ch: jewels){
            mpp[ch]++;
        }

        int cnt = 0;
        for(char ch: stones){
            if(mpp.find(ch) != mpp.end()){
                cnt++;
            }
        }
        return cnt;
    }
};
