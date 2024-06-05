class Solution {
public:
    string intToRoman(int num) {
        string roman[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                          "XL", "X",  "IX", "V",  "IV", "I"};
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string ans = "";
        for (int pos = 0; num > 0; pos++) {
            while (num >= value[pos]) {
                ans += roman[pos];
                num -= value[pos];
            }
        }
        return ans;
    }
};
