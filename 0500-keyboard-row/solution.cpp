class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        //1st make 3 maps and put all characters of a row in a seperate map
        map<char, int> mpp1 = {
            {'q',1}, {'w',1}, {'e',1},{'r',1}, {'t',1}, {'y',1}, {'u',1},
            {'i',1}, {'o',1}, {'p',1}
        };
       
        map<char, int> mpp2 = {
            {'a',1}, {'s',1}, {'d',1},{'f',1}, {'g',1}, {'h',1}, {'j',1},
            {'k',1}, {'l',1}
        };

        map<char, int> mpp3 = {
            {'z',1}, {'x',1}, {'c',1},{'v',1}, {'b',1}, {'n',1}, {'m',1}
        };

        // now hm array me se ek ek word ko lenge & one by one kar ke hr 3nno
        // map me check karnege if pahle map me hi miljayega fir hmm uss word 
        // ko kisi aur map me nahi chech karenge wahi se continue kar jayenge
        // and dushre word ko check karenge b/c since iss map me mila hai 
        // to definitely kisi our map me nahi hoga b/c every map contains 
        // unique character set
        // if iss mapp me koi ek v ek v character nhi mila iss word ka then hmm
        // ab iss map me nahi dhundhenge iss word ko kisis aur map me dhundenge
        vector<string> ansVec;
        for(auto it: words){
            int flag = 1;
            for(int i=0; i<it.size(); i++){
                char ch = (char) tolower(it[i]);
                if(mpp1.find(ch) == mpp1.end()){
                    flag = false;  // word nahi mila
                    break;
                }
            }
            if(flag == 1){ // it means we found this word in row 1(mpp1) so put
                         // it in ansVec and retur and check the next word
               ansVec.push_back(it);
               continue;
            }
           
            // if we have come here it means ye word nhi mila hi mpp1 so check 
            // in mpp2
            flag = 1;
            for(int i=0; i<it.size(); i++){
                char ch = (char) tolower(it[i]);
                if(mpp2.find(ch) == mpp2.end()){
                    flag = false;
                    break;
                }
            }
            if(flag == 1){ // it means we found this word in mpp2(row-2) so
                         // put it in ansVec and retur and check the next word
               ansVec.push_back(it);
               continue;
            }

            // if we have come here it means ye word nhi mila hi mpp1 so check 
            // in mpp3
            flag = 1;
            for(int i=0; i<it.size(); i++){
                char ch = (char) tolower(it[i]);          
                if(mpp3.find(ch) == mpp3.end()){
                    flag = false;
                    break;
                }
            }
            if(flag == 1){ // it means we found this word in mpp3(row-3) so
                         // put it in ansVec and retur and check the next word
               ansVec.push_back(it);
               continue;
            }
        }
        return ansVec;
    }
};
