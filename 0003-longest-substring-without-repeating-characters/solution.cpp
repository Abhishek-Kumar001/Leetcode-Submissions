class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int longestSubstringLen = 0;
        vector<int> charInd(256, -1);

        for(int i=0; i<s.length(); i++){
            char ch = s[i];

            if(charInd[ch] == -1){
                charInd[ch] = i;
            }else{
                int firstOccInd = charInd[ch];
                if(firstOccInd < start){
                    // do nothing
                }else{
                    start = firstOccInd+1;
                }

                charInd[ch] = i;
            }

            longestSubstringLen = max(longestSubstringLen, i-start+1);
        }

        return longestSubstringLen;
    }
};
