class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> frequency(26, 0);
        for(char ch : s){
            frequency[ch-97]++;
        }

        int maxVowelFreq=0, maxConsoFreq =0;
        for(int i=0; i<26; i++){
            char ch = i+97;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                maxVowelFreq = max(maxVowelFreq, frequency[i]);
            }else{
                maxConsoFreq = max(maxConsoFreq, frequency[i]);
            }
        }

        return maxVowelFreq + maxConsoFreq;
    }
};
