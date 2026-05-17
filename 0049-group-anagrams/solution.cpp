class Solution {
    string sortS(string s) {
        int freq[26] = {0};

        for (char c : s)
            freq[c - 97]++;

        string sorted_s = "";
        for (int i = 0; i < 26; i++) {
            while (freq[i]) {
                sorted_s += (char)(i + 97); // Fix 1: use i, not freq[i]
                freq[i]--;
            }
        }
        return sorted_s;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (string s : strs) {
            string s_sorted = sortS(s);
            mpp[s_sorted].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto v : mpp) {
            vector<string> temp;
            for (string x : v.second) { // Fix 2: v.second, not mpp[v]
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans; // Fix 3: missing return
    }
};
