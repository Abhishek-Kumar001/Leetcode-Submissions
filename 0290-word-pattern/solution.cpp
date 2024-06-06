class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // 1st make wordArr form given stirng s
        vector<string> wordArr;
        string word = "";
        for(char ch : s){
            if(ch == ' '){
                wordArr.push_back(word);
                word = "";
            }else{
                word+=ch;
            }
        }
        //at last push the last word   -- VVVVIII
        wordArr.push_back(word);

        // we can be this corner case b/c in Q it is never written that
        // no of word is equeal to size of pattern  so  i gess it may be varry
        if(pattern.size() != wordArr.size()) return false;

        //now traverse pattern string and check char and corresponding word a/c
        // wordArr
        unordered_map<char, string> mpp;
        for(int i=0; i<pattern.size(); i++){
            if(mpp.find(pattern[i]) != mpp.end()){
                //means this patten already in map so check corresponding word
                if(mpp[pattern[i]] != wordArr[i]){
                    //means pahle wale word is differn form this word 
                    // it means pattern has not match
                    return false; 
                }
            }
            else{
                // means this{ pattern, word} has not put yet in map
                mpp[pattern[i]] = wordArr[i];
            }
        }

        // OUR MAP HAS STORED(CONTAINED) UNIQUE keys BUT there may be possible
        // our map contains duplicate values as value
        // if it so then our answer should be false
        // E.g:- pattern = "ab",  s = "dog dog"
        //       Output = flase A/c
        // but a/c our solution it will give us true as output
        // so handle this case also

        set<string> st;
        unordered_map<char, string>::iterator itr;
        for(itr = mpp.begin(); itr!=mpp.end(); itr++){
            st.insert(itr->second);
        }

        if(mpp.size() != st.size()) return false;
        return true;
    }
};
