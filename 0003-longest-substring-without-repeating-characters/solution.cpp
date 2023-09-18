/*

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //hint from apna college
        int start = 0;
        int index[26];
        int len = 0;
        for(int i=0; i<s.length(); i++){
            index[i] = -1;
        }
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(index[ch - 'a'] == -1){
                index[ch - 'a'] = i;
            }
            else{  //it is already found
                if(s[start] == s[i])
                   len = max(len, i-start);
                else
                    len = max(len, i-start + 1);
                //index[ch - 'a'] = i;
                
                start = i;
            }
        }
        if(start == 0){
            return s.length();
        }
        return len;
    }
};

*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int ans =0;

       vector<int> indexArr(256, -1);
       int cnt=0;
       int last =-1;

       for(int i=0; i<s.length(); i++){
           int ind = s[i] ;
           if( indexArr[ind] == -1 ){
               // not come yet this is the first
               cnt++;
               ans = max(ans, i - last);
               indexArr[ind] = i;
           }else{
               // already aa chuka hai ye duplicate hai
               
               // now the question is kya ye last ke pahle aaya hai iff yes ignore
               if( last > indexArr[ind]){
                   //ignore
                   ans = max(ans, i - last);
               }
               else{
                   last =indexArr[ind];
               }
               indexArr[ind] = i; // updating with new index 
           }
       }
       return ans;
    }
};
