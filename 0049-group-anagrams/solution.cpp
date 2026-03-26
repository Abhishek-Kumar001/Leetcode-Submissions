class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<string> strCopy(strs);
        for(int i=0; i<n; i++)
           sort(strCopy[i].begin(), strCopy[i].end());


        vector<vector<string>> ans;
        vector<int> visited(n, 0);

        for(int i=0; i<n; i++){
            if( !visited[i] ){
                visited[i] = 1;
                vector<string> temp;
                temp.push_back(strs[i]);

                for(int j=i+1; j<n; j++){
                    if(strCopy[i] == strCopy[j]){
                        visited[j] = 1;
                        temp.push_back(strs[j]);
                    }
                }

                ans.push_back(temp);
            }
        }

        return ans;
    }
};
