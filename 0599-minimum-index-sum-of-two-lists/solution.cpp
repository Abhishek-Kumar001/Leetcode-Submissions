class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                 vector<string>& list2) {
        // storing word and its index
        map<string, int> mpp;
        for (int i = 0; i < list1.size(); i++) {
            mpp[list1[i]] = i;
        }
 
        // finding the same word in both the string with mini index sum
        int minIndSum = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            if (mpp.find(list2[i]) != mpp.end()) {
                int j = mpp[list2[i]];
                if (i + j < minIndSum) {
                    minIndSum = i + j;
                }
            }
        }

        // finding all the words which r in both the string and have 
        // same mini index sum 
        // b/c there may be multiple words with same mini index sum
        vector<string> ansVec;
        for (int i = 0; i < list2.size(); i++) {
            if (mpp.find(list2[i]) != mpp.end()) {
                int j = mpp[list2[i]];
                if (i + j == minIndSum) {
                    ansVec.push_back(list2[i]);
                }
            }
        }
        return ansVec;
    }
};
