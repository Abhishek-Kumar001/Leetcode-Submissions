class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string , int> prefixCnt;
        int cnt = 0;
        for(int i=0; i<words.size(); i++){
            string s = words[i];
            if(s.length() >= k){
                string prefix = s.substr(0, k);
                prefixCnt[prefix]++;
            }
        }

        for(auto &it : prefixCnt){
            if(it.second >= 2) cnt++;
        }
        return cnt;
    }
};
