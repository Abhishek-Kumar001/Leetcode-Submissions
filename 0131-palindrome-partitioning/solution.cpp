class Solution {
    bool isPalindrome(string s){
        int n = s.length();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-1-i]) return false;
        }
        return true;
    }
    void helper(int ind, string s, vector<string> temp, vector<vector<string>> &ans){
        // base case 
        if(ind == s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<s.length(); i++){
            string subStr = s.substr(ind, i-ind+1);
            if(isPalindrome(subStr)){
                temp.push_back(subStr);
                helper(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        helper(0, s, temp, ans);
        return ans;

    }
};





// #include <vector>
// #include <string>

// using namespace std;

// class Solution {
//     bool isPalindrome(const string& s, int start, int end) {
//         while (start < end) {
//             if (s[start++] != s[end--]) return false;
//         }
//         return true;
//     }

//     void helper(int ind, const string& s, vector<string>& temp, vector<vector<string>>& ans) {
//         if (ind == s.length()) {
//             ans.push_back(temp);
//             return;
//         }

//         for (int i = ind; i < s.length(); ++i) {
//             if (isPalindrome(s, ind, i)) {
//                 temp.push_back(s.substr(ind, i - ind + 1));
//                 helper(i + 1, s, temp, ans);
//                 temp.pop_back();
//             }
//         }
//     }

// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> ans;
//         vector<string> temp;
//         helper(0, s, temp, ans);
//         return ans;
//     }
// };
