class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        for(int i=0; i<strs[0].length(); i++){
            for(int j = 1; j<strs.size(); j++){
                if(strs[j].length() >= i+1){
                   if(strs[0][i] != strs[j][i]) return prefix;
                }else{
                    return prefix;
                }
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};
