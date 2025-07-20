// class Solution {
// public:
//     bool isWithoutRepeating(string s){
//         map<char, int> mpp;

//         for(char ch : s){
//             if(mpp[ch] != 0) return false;
//             mpp[ch]++;
//         }
//         return true;
//     }

//     int lengthOfLongestSubstring(string s) {
//         // M1 - Bruit force (we will generate all the substrings and check for 
//         // longest substring without repeating characters)

//         // TLE
//         // TC - O(n^2 * n)
//         // SC = O(n^2 * n);
        
//         int maxLength = 0;
//         for(int i=0; i<s.size(); i++){
//             string substr = "";
//             for(int j=i; j<s.size(); j++){
//                 substr+=s[j];

//                 if(isWithoutRepeating(substr)){
//                     int currSize = substr.size();
//                     maxLength = max(maxLength, currSize);
//                 }
//             }
//         }

//         return maxLength;
//     }
// };




                      // good 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // M2 optimized
        // sliding window app (apna clg)

        // TLE
        // TC - O(n)
        // SC = O(0);
        
        vector<int> charIndex(256, -1);
        int start = 0, maxLen = 0;
        for(int i=0; i<s.size(); i++){
            int lastPosi = charIndex[ s[i] ];
            if( lastPosi >= start){
                start = lastPosi+1;
            }
            maxLen = max(maxLen, i-start+1);
            charIndex[s[i]] = i;
        }

        return maxLen;
    }
};


