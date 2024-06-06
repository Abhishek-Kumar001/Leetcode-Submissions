class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mpp;
        for(char ch: s){
            mpp[ch]++;
        }

        unordered_map<char, int> :: iterator itr;
        int evenOccurence=0, oddOccurence= 0, oddFlag = 0;
        for(itr=mpp.begin(); itr!=mpp.end(); itr++){
            if(itr->second % 2 == 0) evenOccurence+=itr->second;
            else{
                oddOccurence = oddOccurence+=itr->second-1;
                oddFlag = true;  // this is needed b/c when only 1 char
                // occure 1 time  then we ware going into problem
            }
        }
        if(oddFlag == 0) return evenOccurence; // when no char occurs 
                       // odd no of time
        return evenOccurence + oddOccurence + 1;
    }
};
