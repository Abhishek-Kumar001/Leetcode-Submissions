class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //this codde is not recomended , previous successs 
        // submition is recomemded
        int n = s.length();
        if(s.length() == 0) return 0;

        // skip 0th index duplicates
        int i=0;
        if(n >= 2){
            if( s[0] == s[1]){
                while(i<n && s[0] == s[i]) i++;
                i--;
            }
        }

        map<char, int> mp;      
        int cnt = 0;
        int start = i+1; // start+1
        int maxi = 1;  // for all duplicate
        for(i; i<s.length(); i++){
            int ch = s[i];
            if( mp[ch] < start){
                mp[ch] = i+1; // assiging its index+1 ssince 
                // map me ch[x] == 0 means ye ele nahi aaya hai
                // but for the 1st ele hm 0(index) assing kare
                // to ans me problem aayegi 
          
                int diff = (i+1) - start+ 1;
                maxi = max(maxi , diff);
            }else{            
                start = mp[ch]+1;
                mp[ch] = i+1;  // update with the new index
            }
        }

        return maxi;
    }
};
