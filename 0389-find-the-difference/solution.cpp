class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mpp;
        for(char ch: s){
            mpp[ch]++;
        }

        for(char ch: t){
            if(mpp[ch] == 0){ // not use if(mpp.find(ch) == mpp.end())
                             // b/c it will give us wrong ans here
               return ch; 
            }          
            mpp[ch]--;  // this is VVVVI else we will get wrong ans 
                        // if our s contians duplicates characters
        }
        return 'x'; // this never going to execute. it is just to keep
                    // shup up compiler
    }
};
