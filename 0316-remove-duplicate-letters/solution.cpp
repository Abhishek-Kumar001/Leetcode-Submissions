class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool > present(26 , false);

        vector<int> frequency(26,0);
        for(int i = 0 ; i<s.length(); i++){
             frequency[ s[i] - 'a']++;
        }

        stack<char> stk;

        for(int i=0; i<s.length(); i++){
            if(present[ s[i] - 'a'] == true){
                frequency[ s[i] - 'a' ]--;
            }
            else{
                while(!stk.empty() && stk.top() > s[i] && frequency[ stk.top() - 'a'] > 0){
                    present[ stk.top() - 'a'] = false;
                   // frequency[ stk.top()]--;
                    stk.pop();
                }
                stk.push(s[i]);
                present[s[i] - 'a'] = true;
                frequency[ s[i] - 'a' ]--;
            }
        }

        string ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
