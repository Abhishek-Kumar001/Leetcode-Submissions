class Solution {
    void helper(int ind, string &digits, string temp, vector<string> &ans,
                unordered_map<char, string> &phoneDictionary)
    {
        
        // base case 
        if(ind >= digits.length()){
            ans.push_back(temp);
            return ;
        }

        char digit = digits[ind];
        string allChars = phoneDictionary[digit];

        for(char ch : allChars){
            temp +=ch;
            helper(ind+1, digits, temp, ans, phoneDictionary);
            temp.pop_back();
        }    
    }
public:
    vector<string> letterCombinations(string digits) {
        // Map each digit to its corresponding keypad letters
        unordered_map<char, string> phoneDictionary = {
            {'0', ""},
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> ans;
        string temp = "";

        helper(0, digits, temp, ans, phoneDictionary);
        return ans;
    }
};
