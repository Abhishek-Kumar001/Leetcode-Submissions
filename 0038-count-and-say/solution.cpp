class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string ans = "1";
        for(int i=2; i<=n; i++){
            char last = ans[0];
            int count = 1;
            string res = "";
            
            for(int j=1; j<ans.length(); j++){
                if(ans[j] == last) count++;
                else{
                    res += to_string(count) + last;
                    last = ans[j];
                    count =1;
                }
            }
            res += to_string(count) + last;
            ans = res;
        }

        return ans;
    }
};
