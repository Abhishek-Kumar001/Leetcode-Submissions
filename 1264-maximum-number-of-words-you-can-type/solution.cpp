class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> brokenLettersArr(26, 0);
        for(char ch : brokenLetters){
            brokenLettersArr[ch-97]++;
        }

        bool canType = true;
        int cntWords= 0;
        for(char ch: text){
            if(ch == ' '){
                if(canType) cntWords++;

                canType = true; // again make to true for next word   // V V I
            }
            else if(brokenLettersArr[ch-97]){
                canType = false;
            }
        }
        if(canType) cntWords++;   // v v i

        return cntWords;
    }
};
