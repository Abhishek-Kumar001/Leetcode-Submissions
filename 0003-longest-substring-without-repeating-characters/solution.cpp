class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        vector<int> track(256, -1);
        int maxi = 0;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(track[ch] != -1){  // it means this char is already present
                // start = track[ch]+1;  // wrong : You must never move start backward. eg: abba
                start = max(start, track[ch] + 1);

            }
            maxi = max(maxi, i-start+1);
            track[ch] = i;
        }

        return maxi;
    }
};
