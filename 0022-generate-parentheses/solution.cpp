class Solution {
public:

    void recursion(int noOfOpen, int noOfClose, int n, string &temp, vector<string> &res) {
        if (temp.size() == n) {
            res.push_back(temp);
            return;
        }


        // take 0
        if (noOfOpen > 0) {
            temp.push_back('(');
            recursion(noOfOpen - 1, noOfClose, n, temp, res);
            temp.pop_back(); // backtrack
        }
        
        // take 1 (only if previous was not '1')
        if ((!temp.empty() && noOfClose > 0  &&   noOfOpen < noOfClose) ) {
            temp.push_back(')');
            recursion(noOfOpen, noOfClose - 1, n, temp, res);
            temp.pop_back(); // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        recursion(n, n, 2*n, temp, res); 

        return res;  
    }
};
