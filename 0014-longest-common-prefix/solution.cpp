class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        /*
        // corner case for if vector have only one string 
        if(strs.size() == 1){
            return strs[0];
        }
        */

        string ans="";
        int n= strs.size();

      
        int i=0;
        while( true ){
            int flag =1;
            // // if we are not handling corner case above then run this loop from j=0 so that
            // we can also check that i can't exceed from its strs[0] length other wise 
            // hmara i badhthta jayega and stack overflow aayega b/c hm 
            // i ko iss for loop le andar check kar rhe hai aur hm iss loop me kabhi ja hi nahi rahe
            // jab vector ki size 1 hai 

            for(int j=0; j<n; j++){  // note j ko hm 0 se chalaye hai yahi , it is always the loop 
                                     // from j=0;    
                if( i>= strs[0].length() ||  i >= strs[j].length() ||  strs[j][i] != strs[0][i]){
                    flag = 0;
                }
            }
            if(flag == 1){
                ans.push_back(strs[0][i]);
                
                i++;
            }
            else{
                i++;
                break;
            }
            
        }
        
        return ans;
       
    }
};
