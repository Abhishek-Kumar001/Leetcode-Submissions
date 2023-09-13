class Solution {
public:
    bool isAnagram(string s, string t) {
        int indexArr1[26] = {0};
        int indexArr2[26] = {0};
        
        //if s and t have different lenght then there is no chance of Anagaram
        if(s.length() != t.length()){
            return  false;
        }
        
        // marking every character occurence of 1st sting 
        for(int i=0; i< s.length(); i++){
            indexArr1[s[i]-97]++;
                     
        }
        
        // marking every character occurence of 2nd sting  
        for(int i=0; i< t.length(); i++){       
            indexArr2[t[i]-97]++;           
        }
        
        
        // here no of unique characters of string 1 and string 2 is same of check of Anagram
        for(int i=0; i<26; i++){
            if( indexArr1[i] != indexArr2[i]){
                return false;
            }
        }
        return true;
    }
};
