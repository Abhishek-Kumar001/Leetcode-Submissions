class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> mpp;
        for(char ch : s){
            mpp[ch]++;
        }

        for(char ch: t){
            if(mpp[ch]) mpp[ch]--;
            else return false;
        }
        return true;

    }
};
