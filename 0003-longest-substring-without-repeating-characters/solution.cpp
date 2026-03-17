class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int start = 0;
        int maxLen = 0;
        vector<int> indexArr(256, -1);

        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if( indexArr[ch] != -1 && indexArr[ch] >= start){
                // it means this character has came alrady and that too in after the start 
                start = indexArr[ch]+1;
            }
            maxLen = max(maxLen, i-start+1);
            indexArr[ch] = i;
        }


        return maxLen;
    }
};
