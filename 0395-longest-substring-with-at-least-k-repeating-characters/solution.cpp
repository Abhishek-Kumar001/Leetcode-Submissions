class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();

        int arr[26] = {0};
        for(int i=0; i<n; i++){
            arr[s[i]-'a']++;
        }
        int i=0;
        for( i=0; i<n; i++){
            if(arr[s[i]-'a'] < k) break;
        }

        if(i == n)return i;

        int left = longestSubstring(s.substr(0,i), k);
        int right = longestSubstring(s.substr(i+1), k);

        return max(left, right);
    }
};
