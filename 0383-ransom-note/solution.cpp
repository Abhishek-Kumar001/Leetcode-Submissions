class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
        for(auto it : magazine){
            mpp1[it]++;
        }

        for(auto it : ransomNote){
            mpp2[it]++;
        }

        for(int i=0; i<ransomNote.size(); i++){
            if(mpp2[ransomNote[i]] > mpp1[ransomNote[i]])
                return false;
        }
        return true;
    }
};
