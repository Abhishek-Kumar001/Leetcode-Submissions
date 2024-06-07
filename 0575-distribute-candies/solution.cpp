class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int, int> mpp;
        for(int it : candyType){
            mpp[it]++;
        }
        int n= candyType.size()/2;
        if(mpp.size() >= n) return n;
        return mpp.size();       
    }
};
