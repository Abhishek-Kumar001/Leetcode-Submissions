class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";

        string tempAns = "11";
        for(int i=3; i<=n; i++){
            int cnt = 1;   // vvi not cnt = 0
            string s = "";
            for(int j=0; j<tempAns.size(); j++){
                if(j != tempAns.size()-1  && tempAns[j] == tempAns[j+1]){
                    cnt++;
                }else{
                   s+=(cnt + 48);
                   s+=tempAns[j];

                   cnt = 1;  // vvi not cnt = 0;
                }
            }
            tempAns = s;
        }

        return tempAns;
    }
};
