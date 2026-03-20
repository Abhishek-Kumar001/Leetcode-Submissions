class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        for(int i=0; i+m <= n; i++){
            if(haystack[i] == needle[0]){
                int j=i+1, k=1;
                int flag = true;
                while(k < m){
                    if(haystack[j] != needle[k]){
                        flag = false;
                        break;
                    }
                    j++; k++;
                }
                if(flag == true) return i;
            }
        }
        return -1;
    }
};
