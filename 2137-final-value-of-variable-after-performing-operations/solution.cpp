class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(string value : operations){
            if(value == "++X" || value == "X++") x++;
            else if(value == "--X" || value == "X--") x--;
        }
        return x;
    }
};
