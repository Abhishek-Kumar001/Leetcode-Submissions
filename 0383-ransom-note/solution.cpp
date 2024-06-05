class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>mpp1;
        for(int i=0; i<magazine.size(); i++){
            mpp1[magazine[i]]++;
        }

        map<char, int> mpp2;
        for(auto it: ransomNote){
             mpp2[it]++;
        }

        for(int i=0; i<ransomNote.size(); i++){
            if(mpp2[ransomNote[i]] > mpp1[ransomNote[i]]){
                return false;
            }

        }
        return true;
    }
};
