class Solution {
    void helper(int cnt, int no, vector<int> &digits, vector<int> &vis, set<int> &st){
        if(cnt == 3){
            st.insert(no);
            return;
        }

        for(int i = 0; i < digits.size(); i++){
            if(vis[i]) continue;

            // first digit should not be 0
            if(cnt == 0 && digits[i] == 0) continue;

            // last digit must be even
            if(cnt == 2 && (digits[i] % 2 != 0)) continue;

            vis[i] = 1;
            helper(cnt + 1, no * 10 + digits[i], digits, vis, st);
            vis[i] = 0;
        }
    }

public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());

        set<int> st;   // for unique + sorted
        vector<int> vis(digits.size(), 0);

        helper(0, 0, digits, vis, st);

        return vector<int>(st.begin(), st.end());
    }
};
