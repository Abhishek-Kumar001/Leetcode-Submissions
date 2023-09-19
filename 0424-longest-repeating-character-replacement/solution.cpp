class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 1;
        for(int i=0; i<s.length(); i++){
            int n = k;
            int cnt  = 1;
            for(int j=i+1; j<s.length(); j++){                        
                if(s[j] == s[i]){                   
                    cnt++;
                    ans = max(ans, cnt);  
                }else if( n ){
                    cnt++;
                    n--;
                    ans = max(ans, cnt);                      
                }
                else{
                    break;
                }           
            }

            
            n ; //if still k(i.e  k) bacha hua hai then precess back also
            cnt;
            for(int j=i-1; j>=0; j--){                        
                if(s[j] == s[i]){                   
                    cnt++;
                    ans = max(ans, cnt);  
                }else if( n ){
                    cnt++;
                    n--;
                    ans = max(ans, cnt);                      
                }
                else{
                    break;
                }           
            }
        }

        
        return ans;
    }
};
