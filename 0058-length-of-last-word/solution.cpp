class Solution {
public:
    int lengthOfLastWord(string s) {
        int e = -1;

        for(int i=s.length()-1; i>=0; i--){
            if(e == -1 && s[i] != ' ') e = i;
            else if(s[i] == ' ' && e != -1) return e-i;
        }

        return e-0+1;
    }
};
