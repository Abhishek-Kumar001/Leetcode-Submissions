class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mpp;
        for(int i=0; i<s.size(); i++){
            if(mpp.find(s[i]) != mpp.end()){
                //means allready present 
                if(mpp[s[i]] != t[i]){
                    return false;
                }
            }
            else{
                mpp[s[i]] = t[i];
            }
        }
        // there may be different key have same valus which is false A/c 
        // q eyes 
        // E.g:- s="badc", t="baba";
        // Output :- false  but A/c our solution so far it will give true
        // or E.g:- s="ab", t="xx";
        // Output:- false but A/c our solution so far it will give true
        // so not handle this case

        set<char> set;
        map<char, char> :: iterator itr;
        for(itr=mpp.begin(); itr!=mpp.end(); itr++){
            set.insert(itr->second);
        }
        if(mpp.size() != set.size()) return false;
        return true;
    }
};
