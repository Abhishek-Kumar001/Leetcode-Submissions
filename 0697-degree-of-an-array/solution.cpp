class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // occurenceArr[i] = {occurence, {1st occ index, last occ index}}
        vector<pair<int, pair<int, int>>> occurenceArr(50000, {0, {-1, -1}});

        int maxCnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            int no = nums[i];
            if (occurenceArr[no].first == 0) {
                // this no is come for the first time so make its occurence = 1
                // and its first occurence index= i and last occ ind = i
                occurenceArr[no] = {1, {i, i}};
            } else {
                // already prsent so  fint cnt  and first occurence index
                int cnt = occurenceArr[no].first;
                int firstOccInd = occurenceArr[no].second.first;
                occurenceArr[no] = {cnt + 1, {firstOccInd, i}};

                maxCnt = max(maxCnt, cnt + 1);
            }
        }
       
        if (maxCnt == 1)  // every no apprears only one time so smallest 
             return 1;       // subarray length = 1
           
        //now there may be two or more nos which occ same no of time i.e maxCnt
        // now finding the mini subarray length among all the nos which occurs
        // max no of time i.e maxCnt
        int miniSubArrSize = nums.size();
        for (int i = 0; i < 50000; i++) {
            if (occurenceArr[i].first == maxCnt) {
                int subArrSize = occurenceArr[i].second.second -
                                 occurenceArr[i].second.first + 1;

                miniSubArrSize = min(miniSubArrSize, subArrSize);
            }
        }

        return miniSubArrSize;
    }
};
