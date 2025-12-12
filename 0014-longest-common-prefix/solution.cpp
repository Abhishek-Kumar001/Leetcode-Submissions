class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int flag = 0;
        for(int i=0; i<strs[0].size(); i++){
            for(int j=1; j<strs.size(); j++){
                if(strs[j].size() >= i+1){
                    if(strs[0][i] != strs[j][i]){ 
                        flag = 1;
                        break;
                    }
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) break;
            prefix+=strs[0][i];
        }
        return prefix;
    }
};
