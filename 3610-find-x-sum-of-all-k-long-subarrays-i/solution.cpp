class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        for(int i=0; i+k <= nums.size(); i++){
            // track the occurence of elements for subarray
            unordered_map<int, int> mpp;
            for(int j=i; j<i+k; j++) mpp[nums[j]]++;

            // stroing the number and it's occurence so that we can sort it based
            // on its occurence and it's value b/c we have to take 1st x most occ
            // elements 
            vector<pair<int, int>> topFrequentEle; 
            for(auto [num, occ] : mpp){
                topFrequentEle.push_back({num, occ});
            }
            // sorting based on occ , if occ same take bigger number
            sort(topFrequentEle.begin(), topFrequentEle.end(), [](auto &a, auto&b)
            {  
                if(a.second == b.second) return a.first > b.first;
                else return a.second > b.second;
            });

            // take 1st x most frequent elements
            int temp = 0;
            for(int i=0; i<topFrequentEle.size() && i<x; i++){
                temp +=  topFrequentEle[i].first * topFrequentEle[i].second;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
