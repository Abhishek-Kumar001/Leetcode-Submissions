class Solution {
public:
     string countAndSay(int n) {
       //vvi-->    A/C QUESTION   T(5) ="111221"  NOT   "3112"
         
       //base case
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        string s = "11";
        for(int i=3; i<=n; i++){
            string ansStr;
            int count = 1;
            for(int j=0; j<s.length(); j++){
                if( j != s.length() - 1  &&  s[j] == s[j+1]){
                   count++;
                }
                else{
                    ansStr.push_back( count + 48 );
                    ansStr.push_back( s[j]);
                    count = 1;
                }
            }
            s = ansStr;
        }
         
        return s;
    }
    
    //  ############## IF QUESTION SAYS  T(5) = "3112" NOT "111221"  then this below app work
    /*
    string countAndSay(int n) {
       //   THIS CODE IS MADE OF THINKING  T(5) = "3112" NOT "111221"
       //base case
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        string s = "11";
        for(int i=3; i<=n; i++){
            vector<int> freq(10, 0);
            for(int j=0; j<s.length(); j++){
                freq[ s[j] - 48 ]++;
            }
            
            vector<bool> visi(10, false);
            //string ansStr = new string("");
            string ansStr;
            
            for(int j=0; j<s.length(); j++){
                if( visi[ s[j] -48 ]  == false){
                    visi[ s[j] -48 ] = true;
                    
                    //ansStr= ansStr + freq[ s[j] -48] + s[j]
                    ansStr.push_back( freq[ s[j] - 48 ] + 48 );
                    ansStr.push_back( s[j]);
                }
            }
            s = ansStr;
        }
         
        return s;
    }
    */
};
