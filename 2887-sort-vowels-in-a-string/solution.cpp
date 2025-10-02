class Solution {
public:
    string sortVowels(string s) {
        string t = s;
        vector<int> allVowels;

        for(char ch : t){
            if(ch == 'a' || ch == 'e' || ch =='i' || ch =='o' || ch =='u' || ch == 'A' || ch == 'E' ||
               ch == 'I' || ch == 'O' || ch == 'U'){

                allVowels.push_back(ch);
            }
        }

        sort(allVowels.begin(), allVowels.end());
        int j=0;
        for(int i=0; i<t.size(); i++){
            if(t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i]=='o' || t[i]=='u' || t[i] == 'A' || 
               t[i] == 'E' || t[i] == 'I' || t[i] == 'O' || t[i] == 'U'){

                t[i] = allVowels[j++];
            }
        }

        return t;
    }
};
