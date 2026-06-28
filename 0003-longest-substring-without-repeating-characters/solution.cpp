class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        unordered_map<char, int> mpp;
        int maxLength = 0;

        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(mpp.find(ch) != mpp.end()){
                // it means it is this char is already there 
                int occInd = mpp[ch];
                if(occInd < start)  maxLength = max(maxLength , i-start+1); // do  nothing becuase we are already ahead 
                else start = occInd +1;
            }else{
                // this char is coming for the 1st time
                maxLength = max(maxLength , i-start+1);
            }

            mpp[ch] = i;
        }
        return maxLength;
    }
};
