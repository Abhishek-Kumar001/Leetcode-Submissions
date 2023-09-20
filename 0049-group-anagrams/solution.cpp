

/*
// brout force
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        // sorting each word of given vector but not the original one create dummy string[]
        vector<string> copystrs( strs ) ;
        
        for(int i=0; i<n; i++){
            sort(copystrs[i].begin(), copystrs[i].end());
        }

        // creating index vector and storing the index in group a/c question ;
        vector<vector<int>> indexStore( 0, vector<int>(0)); 
        // to not process the same index again agian mark visited one
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if( visited[i] == 1){
                 continue;
            }
            visited[i] = 1;
            vector<int > temp;
            temp.push_back( i );
            for(int j=i+1; j<n; j++){
                if( copystrs[i] == copystrs[j]){
                    temp.push_back( j );
                    visited[j] = 1;
                }
            }
            indexStore.push_back( temp );
        }

        // now aur ans is stored in indexStore vector we only need to store the index
        // sting and store        
        vector<vector<string>> ans( 0,vector<string>(m) );
        for( auto it: indexStore){
            vector<string> temp;
            for( int ind : it){
                temp.push_back( strs[ind]);
            }
            ans.push_back( temp );
        }
        return ans;
    }
};

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        // sorting each word of given vector but not the original one create dummy string[]
        vector<string> copystrs( strs ) ;
        
        for(int i=0; i<n; i++){
            sort(copystrs[i].begin(), copystrs[i].end());
        }

        vector<vector<string>> ans( 0,vector<string>(m) );
        // to not process the same index again agian mark visited one
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if( visited[i] == 1){
                 continue;
            }
            visited[i] = 1;
            vector<string  > temp;
            temp.push_back( strs[i] );  // not copystrs[i]  b/c copystrs sorted string contain
            // kiya hai par hame original string return karna hia
            for(int j=i+1; j<n; j++){
                if( copystrs[i] == copystrs[j]){
                    temp.push_back( strs[j] );  // not copystrs[j]
                    visited[j] = 1;
                }
            }
            ans.push_back( temp );
        }

        return ans;
    }
};
